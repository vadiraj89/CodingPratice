#include "Controller.h"
#include "Account.h"
#include "Transaction.h"
#include "Wallet.h"
#include<bits/stdc++.h>
using namespace std;

int main()
{
    Controller * cnt = new Controller(0,0.0001);
    cnt->AddWallet("vadiraj",30);
    cnt->AddWallet("vasuki",10);
    cnt->AddWallet("abhi",10);
    cnt->overView();
    cnt->statement("vadiraj");
    cnt->createTransaction("vadiraj","vasuki",10);
    cnt->overView();
    cnt->statement("vadiraj");
    cnt->statement("vasuki");
    cnt->Offer2();
    cnt->overView();
    return 0;
}
