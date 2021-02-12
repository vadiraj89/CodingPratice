#include "Machine.h"
#include "Transaction.h"
#include "State.h"
#include<bits/stdc++.h>
using namespace std;
Machine::Machine(vector<State *> possible_states,vector<Transaction *> trans,State * initial_state)
{
   this->possible_states = possible_states;
   this->trans = trans;
   this->initial_state = initial_state;
   this->curr_state = initial_state;
}

Machine::~Machine()
{
    //dtor
}
void Machine::addState(State * s){
    this->possible_states.push_back(s);
}

void Machine::addTransaction(Transaction * t){
    this->trans.push_back(t);
}

void Machine::TrigeerMachine(bool inp){
    for(auto i:this->trans){
        if(i->curr_state->id == this->curr_state->id && !i->inp^inp){
            cout<<"  we got transaction  ";
            cout<< " switching from "<<this->curr_state->id;
            this->curr_state = i->next_state;
            cout<<" to state " <<this->curr_state->id;
            cout<<" with output "<<i->op<<endl;
            return;
        }
    }
    cout<<"No transaction for current state and input"<<endl;
}
