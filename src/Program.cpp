#include "Program.h"

#include "Atom.h"

Program::Program()
{
    //ctor
}

Program::~Program()
{
    //dtor
}

Atom *Program::findAtom(std::string name)
{
    for (unsigned int a = 0; a < mAtoms.size(); a++)
    {
        if (mAtoms[a]->getName() == name)
            return mAtoms[a];
    }

    return NULL;
}
