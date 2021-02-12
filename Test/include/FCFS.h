#ifndef FCFS_H
#define FCFS_H

#include <Scheduler.h>


class FCFS : public Scheduler
{
    public:
        FCFS(int t);
        vector<pair<int,Job *>> getPQ(vector<Job *> jobs);
        virtual ~FCFS();

    protected:

    private:
};

#endif // FCFS_H
