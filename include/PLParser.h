#ifndef PLPARSER_H
#define PLPARSER_H

#include <string>
#include <vector>

#include "PLTokenizer.h"

class Program;
class CompoundTerm;
class Clause;

class PLParser
{
    public:
        PLParser();
        virtual ~PLParser();

        void parseString(Program *program, std::string str);

    protected:
        CompoundTerm *buildCompoundTerm(Clause *clause, Program *program, std::vector <PLToken> &tokens, int &start, bool isRule = false, bool isQuery = false);

        PLTokenizer *mTokenizer;

    private:
};

#endif // PLPARSER_H
