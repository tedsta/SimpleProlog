#ifndef CLAUSE_H
#define CLAUSE_H

#include <vector>
#include <string>

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

        CompoundTerm *getHead(){return mHead;}

        void setHead(CompoundTerm *head){mHead=head;}
        void addGoal(Goal *goal){mGoals.push_back(goal);}

        void addVariable(Variable *var){mVariables.push_back(var);}
        Variable *findVariable(std::string name);

    protected:
        CompoundTerm *mHead;
        std::vector <Goal*> mGoals;
        std::vector <Variable*> mVariables;

    private:
};

#endif // CLAUSE_H
