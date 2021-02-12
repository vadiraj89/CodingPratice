#ifndef SMALLEXECUTIONTIME_H
#define SMALLEXECUTIONTIME_H

#include <Scheduler.h>


class SmallExecutionTime : public Scheduler
{
    public:
        SmallExecutionTime(int t);
        vector<pair<int,Job *>> getPQ(vector<Job *> jobs);
        virtual ~SmallExecutionTime();

    protected:

    private:
};

#endif // SMALLEXECUTIONTIME_H
