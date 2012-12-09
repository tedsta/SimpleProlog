#include "PLParser.h"

#include "Prolog.h"

PLParser::PLParser()
{
    mTokenizer = new PLTokenizer;
}

PLParser::~PLParser()
{
    //dtor
}

void PLParser::parseString(Program *program, std::string str)
{
    std::vector <PLToken> tokens = mTokenizer->tokenizeString(str);

    CompoundTerm *ct = NULL;

    enum
    {
        FACT,
        RULE
    };

    int start = 0; //start of the current sentence
    int end; //end of the sentence
    bool isRule; //fact or rule
    bool isQuery; //is it a query?

    while (start < (int)tokens.size())
    {
        isRule = false; //default is fact

        //get some sentence info
        for (unsigned int t = start; t < tokens.size(); t++)
        {
            if (tokens[t].mType == PLToken::INFER)
                isRule = true;
            else if (tokens[t].mType == PLToken::QUERY)
                isQuery = true;
            else if (tokens[t].mType == PLToken::END)
            {
                end = t;
                break;
            }
        }

        if (isQuery)
        {
            if (tokens[start].mType == PLToken::QUERY)
                start++; //skip query
            //TODO: else, some kind of error
        }

        //build the first compound term of the clause
        Clause *clause = new Clause;
        ct = buildCompoundTerm(clause, program, tokens, start, isRule, isQuery);
        clause->setHead(ct);

        if (isQuery)
        {
            clause->setType(ClauseType::QUERY);

            Goal goal(ct);
            goal.solve(program);
        }
        else if (isRule) //build rule
        {
            clause->setType(ClauseType::RULE);

            std::vector <Goal*> goals;

            for (;start < end; start++)
            {
                if (tokens[start].mType == PLToken::NAME)
                    clause->addGoal(new Goal(buildCompoundTerm(clause, program, tokens, start, isRule)));
            }
        }
        else //fact
            clause->setType(ClauseType::FACT);

        program->addClause(clause);

        start = end+1; //skip the period
    }
}

CompoundTerm *PLParser::buildCompoundTerm(Clause *clause, Program *program, std::vector <PLToken> &tokens, int &start, bool isRule, bool isQuery)
{
    //make sure we start with a name
    if (tokens[start].mType != PLToken::NAME)
        return NULL;

    Atom *atom;
    Term **ct_args;
    std::vector <std::string> args;

    atom = program->findAtom(tokens[start].mData);
    if (!atom)
    {
        atom = new Atom(tokens[start].mData);
        program->addAtom(atom);
    }
    start++; //skip atom name

    //get args
    start++; //skip open parentheses
    for (; start < (int)tokens.size(); start++)
    {
        //another parameter
        if (tokens[start].mType == PLToken::NAME)
            args.push_back(tokens[start].mData);
        else if (tokens[start].mData == ")")
            break;
    }
    start++; //skip close parentheses

    //build ct_args
    ct_args = new Term*[args.size()];
    for (unsigned int a = 0; a < args.size(); a++)
    {
        if (isRule) //rules only have variables
        {
            ct_args[a] = clause->findVariable(args[a]);
            if (!ct_args[a])
            {
                ct_args[a] = new Variable(args[a]);
                clause->addVariable((Variable*)ct_args[a]);
            }
        }
        else if (isQuery) //query
        {
            Term *tmp = (Term*)program->findAtom(args[a]);
            if (!tmp)
                tmp = clause->findVariable(args[a]);
            if (!tmp) //doesn't exist, create a variable
            {
                tmp = new Variable(args[a]);
                clause->addVariable((Variable*)tmp);
            }
            ct_args[a] = tmp;
        }
        else //fact
        {
            Atom *tmp = program->findAtom(args[a]);
            if (!tmp)
            {
                tmp = new Atom(args[a]);
                program->addAtom(tmp);
            }
            ct_args[a] = tmp;
        }
    }

    return new CompoundTerm(atom, ct_args, args.size());
}
