#ifndef VARIABLE_H
#define VARIABLE_H

#include <iostream>
#include <string>

#include "Term.h"

class Variable : public Term
{
    public:
        Variable(std::string name);
        virtual ~Variable();

        virtual bool unify(Term *other);

        virtual void print();

        void reset(){mInstance=this;}

        //accessors
        std::string getName(){return mName;}

        //mutators
        void setName(std::string name){mName=name;}

    protected:
        std::string mName; //name of this variable

        Term *mInstance; //the term we are replacing this variable with

    private:
};

#endif // VARIABLE_H
