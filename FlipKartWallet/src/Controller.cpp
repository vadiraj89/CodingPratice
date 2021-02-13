#include "Controller.h"
#include "Account.h"
#include "Transaction.h"
#include "Wallet.h"
#include<bits/stdc++.h>
using namespace std;
Controller::Controller(double bl,double translimit)
{
    this->accounts= vector<Account *>();
    this->balance_limit = bl;
    this->trans_limit = translimit;
}

Controller::~Controller()
{
    //dtor
}

void Controller::AddWallet(string id,double balance){
    if(balance<=this->balance_limit){
        cout<<" Sorry , cant create Wallet with min balance";
    }
    else{
        Wallet * newWallet = new Wallet(id,balance);
        this->accounts.push_back(new Account(newWallet));
    }
}

void Controller::overView(){
    for(auto i:this->accounts){
        cout<<" id -> "<<i->details->account_id<<" ";
        cout<<" Rewards -> "<<i->details->rewards<<" ";
        cout<<" balance->"<<i->details->balance<<"\n";
    }
}
Account * Controller::getAccount(string id){
    for(auto i:this->accounts){
        if(i->details->account_id==id){
            return i;
        }
    }
    return  NULL;
}
void Controller::statement(string acc_id){
    Account * acc = this->getAccount(acc_id);
    if(acc==NULL){
        cout<<" No account "<<endl;
    }
    else
    {
        cout<<" Account Got details! Fetching Transactions "<<endl;
        acc->getStatement();
    }
}
void Controller::createTransaction(string p_acc_id,string r_acc_id,double amt){
   Account * p_acc = this->getAccount(p_acc_id);
   Account * s_acc = this->getAccount(r_acc_id);
   if(p_acc==NULL || s_acc==NULL){
    cout<<" Unable to fetch account Deatils !cannot move further"<<endl;
    return;
   }
   if(amt<this->trans_limit){
    cout<<" Min Tran amt is less cannot step further"<<endl;
    return;
   }
   if((p_acc->details->balance-amt)<=this->balance_limit){
    cout<<" Insufficient Funds in From Account "<<endl;
    return;
   }
   Transaction * newtrans = new Transaction(p_acc->details,s_acc->details,amt);
   p_acc->trans.push_back(newtrans);
   s_acc->trans.push_back(newtrans);
   cout<<"Transaction went Absolutely Fine!"<<endl;
   if(newtrans->Offer1()){
    cout<<" Got an Offer "<<endl;
   }
   else{
    cout<<" Sorry No Offer"<<endl;
   }
}
bool mycomp(const pair<int,Account *> &p1,const pair<int,Account *> &p2){
    if(p1.first>p2.first){
        return true;
    }
    else if(p1.first<p2.first){
        return false;
    }
    else{
        if(p1.second->details->balance>p2.second->details->balance){
            return true;
        }
        else if(p1.second->details->balance>p2.second->details->balance){
            return false;
        }
        else{
                time_t currt;
                time(&currt);
            return difftime(currt,p1.second->details->account_valid_from)>difftime(currt,p2.second->details->account_valid_from);
        }
    }
}
void Controller::Offer2(){
    vector<pair<int,Account *>> trans_account_pair;
    for(auto i:this->accounts){
        trans_account_pair.push_back(make_pair(i->trans.size(),i));
    }
    sort(trans_account_pair.begin(),trans_account_pair.end(),mycomp);
    int i=1;
    int index = 0;
    while(index<this->accounts.size() && i<=3){
        if(i==1){
            trans_account_pair[index].second->details->balance+=10;
            trans_account_pair[index].second->details->rewards+=10;
            index++;
            i++;
        }
        else if(i==2){
            trans_account_pair[index].second->details->balance+=5;
            trans_account_pair[index].second->details->rewards+=5;
            index++;
            i++;
        }
        else {
            trans_account_pair[index].second->details->balance+=2;
            trans_account_pair[index].second->details->rewards+=2;
            index++;
            i++;
        }
    }
}
