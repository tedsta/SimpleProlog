#ifndef TRUETERM_H
#define TRUETERM_H

#include "Term.h"

class TrueTerm : public Term
{
    public:
        TrueTerm(){}
        virtual ~TrueTerm(){}

        virtual bool unify(Term *term){return true;}

    protected:
    private:
};

#endif // TRUETERM_H
