#include "Goal.h"

#include <iostream>

#include "CompoundTerm.h"
#include "Clause.h"
#include "Program.h"

Goal::Goal(CompoundTerm *term)
{
    mCompoundTerm = term;
}

Goal::~Goal()
{
    //dtor
}

bool Goal::satisfied(Program *program)
{
    for (int c = 0; c < program->getClauseCount(); c++)
    {
        if (mCompoundTerm != program->getClause(c)->mHead &&
            ((mCompoundTerm->unify(program->getClause(c)->mHead) && program->getClause(c)->getType() == ClauseType::FACT) ||
             (program->getClause(c)->mHead->unify(mCompoundTerm) && program->getClause(c)->getType() == ClauseType::RULE)))
        {
            std::cout << "Head Match: ";
            program->getClause(c)->print();
            std::cout << std::endl;
            if (program->getClause(c)->satisfied(program))
                return true;
        }

        /*for (unsigned int g = 0; g < program->getClause(c)->mGoals.size(); g++)
        {
            if (mCompoundTerm != program->getClause(c)->mGoals[g]->mCompoundTerm &&
                program->getClause(c)->mGoals[g]->mCompoundTerm->unify(mCompoundTerm))
            {
                std::cout << "Body Match: ";
                program->getClause(c)->print();
                std::cout << std::endl;
                Goal *check = new Goal(program->getClause(c)->mHead);
                if (check->satisfied(program))
                    return true;
            }
        }*/

        program->getClause(c)->reset();
    }

    return false;
}

void Goal::solve(Program *program)
{
    if (satisfied(program))
        std::cout << "Yes\n";
    else
        std::cout << "No\n";
}
