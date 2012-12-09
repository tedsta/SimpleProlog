#ifndef GOAL_H
#define GOAL_H

class CompoundTerm;
class Program;

class Goal
{
    friend class Clause;

    public:
        Goal(CompoundTerm *term);
        virtual ~Goal();

        bool satisfied(Program *program);
        void solve(Program *program);

    protected:
        CompoundTerm *mCompoundTerm;

    private:
};

#endif // GOAL_H
