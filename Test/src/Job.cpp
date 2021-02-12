#include "Job.h"
#include <bits/stdc++.h>
using namespace std;
Job::Job(string id,int et,int dl,int p,string user)
{
    this->id = id;
    this->exe_time_sec = et;
    this->deadline = dl;
    this->priority = p;
    this->usertype = user;
    time(&this->entry_time);
    this->status = "entered";
}

Job::~Job()
{
    //dtor
}
