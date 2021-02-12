#include "Game.h"
#include "Player.h"
#include "Ship.h"
#include <bits/stdc++.h>

using namespace std;
Game::Game(Player * p1,Player * p2)
{
    this->p1 = p1;
    this->p2 = p2;
    for(auto i:this->p1->ships){
        this->ships.push_back(i);
    }
    for(auto i:this->p2->ships){
        this->ships.push_back(i);
    }
    this->next_move = p1;
}

Game::~Game()
{
    //dtor
}

void Game::makeMove(Player * player,int x,int y){
    if(player->pid!=this->next_move->pid){
            cout<<" Not current player";
        return;
    }
    else{
        if(this->next_move->pid==this->p1->pid){
                int p1success = this->p2->tryHit(make_pair(x,y));
            if(p1success==1){
                cout<<"opponent got hurt "<<endl;
              }
            else if(p1success==2){
                cout<<"opponent got hurt and all ships destroyed p1 is winner Hurray"<<endl;
              }
            else {
                cout<<"Uff target missed wait for next turn"<<endl;
            }
           this->next_move = this->p2;
        }
        else{
            int p2success = this->p1->tryHit(make_pair(x,y));
            if(p2success==1){
                cout<<"opponent got hurt "<<endl;
              }
            else if(p2success==2){
                cout<<"opponent got hurt and all ships destroyed p2 is winner Hurray"<<endl;
              }
            else {
                cout<<"Uff target missed wait for next turn"<<endl;
            }
           this->next_move = this->p1;
        }
    }
}
