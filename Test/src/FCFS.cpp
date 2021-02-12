#include "FCFS.h"

FCFS::FCFS(int t):Scheduler(t)
{
    //ctor
}

FCFS::~FCFS()
{
    //dtor
}

bool sortbysec(const pair<int,Job *> &a, const pair<int,Job *> &b)
{

        return a.second->priority<b.second->priority;


}
vector<pair<int,Job *>> FCFS::getPQ(vector<Job *> jobs){
    vector<pair<int,Job *>> vp;
    for(auto i:jobs){
        vp.push_back(make_pair(i->exe_time_sec,i));
    }
    sort(vp.begin(),vp.end(),sortbysec);

    return vp;
}
