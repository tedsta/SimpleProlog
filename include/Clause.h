#ifndef CLAUSE_H
#define CLAUSE_H

#include <vector>
#include <string>

namespace ClauseType
{
    enum
    {
        FACT,
        RULE,
        QUERY
    };
}

class Goal;
class Variable;
class CompoundTerm;
class Program;

class Clause
{
    friend class Goal;

    public:
        Clause(CompoundTerm *head = NULL, std::vector <Goal*> body = std::vector<Goal*>());
        virtual ~Clause();

        bool satisfied(Program *program);

        void print();

        void reset();

        void addGoal(Goal *goal){mGoals.push_back(goal);}

        void addVariable(Variable *var){mVariables.push_back(var);}
        Variable *findVariable(std::string name);

        //accessors
        CompoundTerm *getHead(){return mHead;}
        int getType(){return mType;}

        //mutators
        void setHead(CompoundTerm *head){mHead=head;}
        void setType(int type){mType=type;}

    protected:
        CompoundTerm *mHead;
        std::vector <Goal*> mGoals;
        std::vector <Variable*> mVariables;

        int mType; //fact, rule, or query?

    private:
};

#endif // CLAUSE_H
