#include "Variable.h"

Variable::Variable(std::string name)
{
    mName = name;
    mInstance = this;
}

Variable::~Variable()
{
    //dtor
}

bool Variable::unify(Term *other)
{
    if (mInstance != this)
        return mInstance->unify(other);

    mInstance = other;

    return true;
}

void Variable::print()
{
    std::cout << mName;
    if (mInstance != this)
    {
        std::cout << " -> ";
        mInstance->print();
    }
}
