#include "Clause.h"

#include <iostream>

#include "Program.h"
#include "Variable.h"
#include "CompoundTerm.h"
#include "Goal.h"

Clause::Clause(CompoundTerm *head, std::vector <Goal*> body)
{
    mHead = head;
    mGoals = body;
}

Clause::~Clause()
{
    //dtor
}

bool Clause::satisfied(Program *program)
{
    for (unsigned int g = 0; g < mGoals.size(); g++)
    {
        if (!mGoals[g]->satisfied(program))
        {
            return false;
        }
    }

    return true;
}

void Clause::print()
{
    mHead->print();
    std::cout << " :- ";
    for (unsigned int g = 0; g < mGoals.size(); g++)
    {
        mGoals[g]->mCompoundTerm->print();
        if (g < mGoals.size()-1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

Variable *Clause::findVariable(std::string name)
{
    for (unsigned int v = 0; v < mVariables.size(); v++)
    {
        if (mVariables[v]->getName() == name)
            return mVariables[v];
    }

    return NULL;
}
