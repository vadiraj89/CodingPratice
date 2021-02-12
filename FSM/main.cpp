#include "Machine.h"
#include "Transaction.h"
#include "State.h"
#include<bits/stdc++.h>
using namespace std;
using namespace std;

int main()
{
    State * s1 = new State("state1");
    State * s2 = new State("state2");
    State * s3 = new State("state3");

    vector<State *> sts;
    sts.push_back(s1);
    sts.push_back(s2);
    sts.push_back(s3);

    vector<Transaction *> trn;
    trn.push_back(new Transaction(s1,s2,true,1));
    trn.push_back(new Transaction(s1,s2,false,2));
    trn.push_back(new Transaction(s2,s3,true,3));
    trn.push_back(new Transaction(s2,s3,false,4));
    trn.push_back(new Transaction(s3,s1,true,5));


    Machine * mc = new Machine(sts,trn,s1);
    State * s4= new State("state4");
    mc->addState(s4);
    mc->addTransaction(new Transaction(s3,s4,false,6));
    mc->addTransaction(new Transaction(s4,s1,true,7));

    mc->TrigeerMachine(true);
    mc->TrigeerMachine(true);
    mc->TrigeerMachine(false);
    mc->TrigeerMachine(false);
    return 0;
}
