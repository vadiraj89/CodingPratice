#include "Transaction.h"
#include "Wallet.h"
#include<bits/stdc++.h>
using namespace std;
Transaction::Transaction(Wallet * f,Wallet * sec,double amt)
{
    this->first_party = f;
    this->second_party = sec;
    this->transferred_amount = amt;
    this->first_party->balance=this->first_party->balance-amt;
    this->second_party->balance=this->second_party->balance+amt;
}

Transaction::~Transaction()
{
    //dtor
}

bool Transaction::Offer1(){
  if(this->first_party->balance==this->second_party->balance){

    this->first_party->balance+=10;
    this->first_party->rewards+=10;
    this->second_party->balance+=10;
    this->second_party->rewards+=10;
    return true;
  }
  else return false;
}
