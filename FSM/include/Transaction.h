#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "State.h"
#include<bits/stdc++.h>
using namespace std;

class Transaction
{
    public:
        State * curr_state;
        bool inp;
        State * next_state;
        int op;
        Transaction(State * cr,State * op,bool input,int inp);
        virtual ~Transaction();

    protected:

    private:
};

#endif // TRANSACTION_H
