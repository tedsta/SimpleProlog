#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include <string>

class Clause;
class Atom;

class Program
{
    public:
        Program();
        virtual ~Program();

        int getClauseCount(){return mClauses.size();}
        Clause *getClause(int index){return mClauses[index];}
        void addClause(Clause *clause){mClauses.push_back(clause);}

        void addAtom(Atom *atom){mAtoms.push_back(atom);}
        Atom *findAtom(std::string name);

    protected:
        std::vector <Clause*> mClauses;
        std::vector <Atom*> mAtoms;
    private:
};

#endif // PROGRAM_H
