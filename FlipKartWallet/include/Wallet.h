#ifndef WALLET_H
#define WALLET_H
#include<bits/stdc++.h>
using namespace std;

class Wallet
{
    public:
        string account_id;
        double balance;
        double rewards;
        time_t account_valid_from;
        Wallet(string id,double balance);
        virtual ~Wallet();

    protected:

    private:
};

#endif // WALLET_H
