#include "SmallExecutionTime.h"
#include "Scheduler.h"
#include "Job.h"
#include <bits/stdc++.h>
using namespace std;

SmallExecutionTime::SmallExecutionTime(int t):Scheduler(t)
{
    //ctor
}

SmallExecutionTime::~SmallExecutionTime()
{
    //dtor
}
bool sortbysec1(const pair<int,Job *> &a, const pair<int,Job *> &b)
{
    if(a.first<b.first){
        return true;
    }
    else if(a.first>b.first){
        return false;
    }
    else{
        return a.second->priority<b.second->priority;
    }

}
vector<pair<int,Job *>> SmallExecutionTime::getPQ(vector<Job *> jobs){
    vector<pair<int,Job *>> vp;
    for(auto i:jobs){
        vp.push_back(make_pair(i->exe_time_sec,i));
    }
    sort(vp.begin(),vp.end(),sortbysec1);

    return vp;
}
