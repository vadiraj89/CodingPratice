#ifndef MACHINE_H
#define MACHINE_H
#include "Transaction.h"
#include "State.h"
#include<bits/stdc++.h>
using namespace std;

class Machine
{
    public:
        vector<State *> possible_states;
        vector<Transaction *> trans;
        State * initial_state;
        State * curr_state;

        Machine(vector<State *> possible_states,vector<Transaction *> trans,State * initial_state);
        void addState(State * s);
        void addTransaction(Transaction * t);
        void TrigeerMachine(bool inp);
        virtual ~Machine();

    protected:

    private:
};

#endif // MACHINE_H
