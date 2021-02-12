#include "Scheduler.h"
#include "Job.h"
#include <bits/stdc++.h>
using namespace std;
Scheduler::Scheduler(int t)
{
    this->threads = t;
    for(int i=0;i<t;i++){
        queue<Job *> q ;
        this->thread_queue.push_back(q);
    }
}

Scheduler::~Scheduler()
{
    //dtor
}

//virtual vector<pair<int,Job *>> Scheduler::getPQ(vector<Job *> jobs)=0;
void Scheduler::schedule(vector<Job *> jobs){
   vector<pair<int,Job *>>  pq = this->getPQ(jobs);
    for(auto i:pq){

        Job * job = i.second;

        time_t currenttime;
        time(&currenttime);
        if(difftime(currenttime, job->entry_time)<=job->deadline){

            int index = 0;
            int queue_size = INT_MAX;
            for(int i=0;i<this->thread_queue.size();i++){
                if(this->thread_queue[i].size()<queue_size){
                    index = i;
                    queue_size = this->thread_queue[i].size();
                }
            }

            this->thread_queue[index].push(job);
        }

    }
}
