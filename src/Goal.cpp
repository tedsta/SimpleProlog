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
        if (mCompoundTerm != program->getClause(c)->mHead && mCompoundTerm->unify(program->getClause(c)->mHead))
        {
            if (program->getClause(c)->satisfied(program))
                return true;
        }

        for (unsigned int g = 0; g < program->getClause(c)->mGoals.size(); g++)
        {
            if (mCompoundTerm != program->getClause(c)->mGoals[g]->mCompoundTerm &&
                program->getClause(c)->mGoals[g]->mCompoundTerm->unify(mCompoundTerm))
            {
                Goal *check = new Goal(program->getClause(c)->mHead);
                if (check->satisfied(program))
                    return true;
            }
        }
    }

    return false;
}

void Goal::solve(Program *program)
{
    if (satisfied(program))
        std::cout << "Yes\n";
}
