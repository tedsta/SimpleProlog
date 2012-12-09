#ifndef ATOM_H
#define ATOM_H

#include <iostream>
#include <string>

#include "Term.h"

class Atom : public Term
{
    public:
        Atom(std::string name)
        {
            mName=name;
        }

        virtual ~Atom(){}

        virtual bool unify(Term *other){return this==other;}

        virtual void print(){std::cout << mName;}

        //operators
        bool operator==(Atom other){return other.getName()==mName;}

        //accessors
        std::string getName(){return mName;}

        //mutators
        void setName(std::string name){mName=name;}

    protected:
        std::string mName;
    private:
};

#endif // ATOM_H
