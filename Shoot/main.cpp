#include "Game.h"
#include "Player.h"
#include "Ship.h"
#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<Ship *> p1ships;
    vector<Ship *> p2ships;
    p1ships.push_back(new Ship(1,2));
    p1ships.push_back(new Ship(2,3));
    p2ships.push_back(new Ship(1,2));
    p2ships.push_back(new Ship(2,3));
    Player * p1 = new Player("vadi","gulf",p1ships);
    Player * p2 = new Player("vasu","arab",p2ships);
    Game * newgame = new Game(p1,p2);
    newgame->makeMove(p1,1,2);
    newgame->makeMove(p2,1,2);
    newgame->makeMove(p1,2,3);
    return 0;
}
