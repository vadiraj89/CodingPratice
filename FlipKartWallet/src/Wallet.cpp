#include "Wallet.h"
#include<bits/stdc++.h>
using namespace std;
Wallet::Wallet(string id,double balance)
{
    this->account_id = id;
    this->balance=balance;
    this->rewards = 0;
    time(&this->account_valid_from);
}

Wallet::~Wallet()
{
    //dtor
}
