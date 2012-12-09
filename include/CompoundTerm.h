#ifndef COMPOUNDTERM_H
#define COMPOUNDTERM_H

#include "Term.h"

class Atom;

class CompoundTerm : public Term
{
    public:
        CompoundTerm(Atom *atom, Term **args, int arity);
        virtual ~CompoundTerm();

        virtual bool unify(Term *other);

        virtual void print();

    protected:
        Atom *mAtom;
        Term **mArgs;
        int mArity;

    private:
};

#endif // COMPOUNDTERM_H
