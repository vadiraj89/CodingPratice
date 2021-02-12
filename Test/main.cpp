#include "SmallExecutionTime.h"
#include "Scheduler.h"
#include "Job.h"
#include "FCFS.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    FCFS * sech = new FCFS(2);
    vector<Job *> inputs;
    inputs.push_back(new Job("job1",3,100,1,"admin"));
    inputs.push_back(new Job("job2",2,100,0,"admin"));
    inputs.push_back(new Job("job3",1,100,2,"admin"));
    sech->schedule(inputs);
    int index=1;
    for(auto i:sech->thread_queue){
            cout<<index<<" Thread ";
        while(!i.empty()){
            cout<<i.front()->id <<" ";
            i.pop();
        }
        index++;
        cout<<"\n";
    }
    return 0;
}
