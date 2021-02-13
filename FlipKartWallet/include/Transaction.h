#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "Wallet.h"
#include<bits/stdc++.h>
using namespace std;
class Transaction
{
    public:
        Wallet * first_party;
        Wallet * second_party;
        double transferred_amount;
        Transaction(Wallet * f,Wallet * sec,double amt);
        virtual ~Transaction();
        bool Offer1();
    protected:

    private:
};

#endif // TRANSACTION_H
