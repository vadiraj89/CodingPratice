#include "Transaction.h"
#include "State.h"
#include<bits/stdc++.h>
using namespace std;
Transaction::Transaction(State * cr,State * op,bool inp,int oper)
{
    this->curr_state = cr;
    this->next_state = op;
    this->inp = inp;
    this->op = oper;
}

Transaction::~Transaction()
{
    //dtor
}
