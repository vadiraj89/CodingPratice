#include "Player.h"
#include "Ship.h"
#include <bits/stdc++.h>

using namespace std;
Player::Player(string pid,string fid,vector<Ship *> sh)
{
    this->pid=pid;
    this->fid=fid;
    this->ships = sh;
}

Player::~Player()
{
    //dtor
}

int Player:: tryHit(pair<int,int> pos){
    int successforhit=-1;
    int successforwin=2;
    for(auto i:this->ships){

        if(i->position.first==pos.first && i->position.second==pos.second && i->status=="armed"){

            i->status="destroyed";
            successforhit = 1;
        }
    }
    for(auto i:this->ships){

        if(i->status=="armed"){
            successforwin=-1;

        }

    }

    if(successforwin>0){
        return successforwin;
    }
    else{

        return successforhit;
    }

}
