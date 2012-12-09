#ifndef TERM_H
#define TERM_H


class Term
{
    public:
        Term(){}
        virtual ~Term(){}

        virtual bool unify(Term *other) = 0;

        virtual void print() = 0;
};

#endif // TERM_H
