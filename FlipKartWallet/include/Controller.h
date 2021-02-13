#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Account.h"
#include "Transaction.h"
#include "Wallet.h"
#include<bits/stdc++.h>
using namespace std;
class Controller
{
    public:

        vector<Account *> accounts;
        double balance_limit;
        double trans_limit;
        Controller(double d1,double d2);
        void AddWallet(string id,double balance);
        void overView();
        Account * getAccount(string id);
        void statement(string acc_id);
        void createTransaction(string p_acc_id,string r_acc_id,double amt);
        void Offer2();
        virtual ~Controller();

    protected:

    private:
};

#endif // CONTROLLER_H
