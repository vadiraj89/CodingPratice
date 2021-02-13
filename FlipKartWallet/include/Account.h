#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "Transaction.h"
#include "Wallet.h"
#include<bits/stdc++.h>
using namespace std;
class Account
{
    public:
        Wallet * details;
        vector<Transaction *> trans;
        Account(Wallet * details);
        void getStatement();
        virtual ~Account();

    protected:

    private:
};

#endif // ACCOUNT_H
