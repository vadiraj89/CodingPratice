#ifndef SCHEDULER_H
#define SCHEDULER_H
#include "Job.h"
#include <bits/stdc++.h>
using namespace std;
class Scheduler
{
    public:
        int threads;
        vector<queue<Job *>> thread_queue;
        Scheduler(int t);
        virtual ~Scheduler();
        virtual vector<pair<int,Job *>> getPQ(vector<Job *> pq)=0;
        void schedule(vector<Job *> jobs);
    protected:

    private:
};

#endif // SCHEDULER_H
