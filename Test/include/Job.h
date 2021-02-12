#ifndef JOB_H
#define JOB_H
#include <bits/stdc++.h>
using namespace std;
class Job
{
    public:
        string id;
        int exe_time_sec;
        int deadline;
        int priority;
        string usertype;
        time_t entry_time;
        string status;
        Job(string id,int et,int dl,int p,string user);
        virtual ~Job();

    protected:

    private:
};

#endif // JOB_H
