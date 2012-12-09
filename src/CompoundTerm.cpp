#include "CompoundTerm.h"

#include "Atom.h"

CompoundTerm::CompoundTerm(Atom *atom, Term **args, int arity)
{
    mAtom = atom;
    mArgs = args;
    mArity = arity;
}

CompoundTerm::~CompoundTerm()
{
    delete[] mArgs;
}

bool CompoundTerm::unify(Term *other)
{
    CompoundTerm *ct = (CompoundTerm*)other;

    if (mAtom != ct->mAtom)
        return false;

    if (mArity != ct->mArity)
        return false;

    for (int i = 0; i < mArity; i++)
    {
        if (!mArgs[i]->unify(ct->mArgs[i]))
            return false;
    }

    return true;
}

void CompoundTerm::print()
{
    std::cout << mAtom->getName() << "(";

    for (int i = 0; i < mArity; i++)
    {
        mArgs[i]->print();
        if (i < mArity-1)
            std::cout << ", ";
    }

    std::cout << ")";
}
