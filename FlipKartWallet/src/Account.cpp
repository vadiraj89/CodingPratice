#include "Account.h"
#include "Transaction.h"
#include "Wallet.h"
#include<bits/stdc++.h>
using namespace std;
Account::Account(Wallet * det)
{
    this->details = det;
    this->trans = vector<Transaction *> ();
}

Account::~Account()
{
    //dtor
}

void Account::getStatement(){
    if(this->trans.size()==0){
        cout<<" No Transactions !"<<endl;
        return;
    }
  for(auto i:this->trans){

  cout<<" paid from "<<i->first_party->account_id<<" paid To "<<i->second_party->account_id<<" Amout "<<i->transferred_amount<<endl;
  cout<<" Rewards from Wallet "<<this->details->rewards<<endl;
  }
}
