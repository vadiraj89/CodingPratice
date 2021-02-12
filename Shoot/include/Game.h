#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Ship.h"
#include <bits/stdc++.h>

using namespace std;

class Game
{
    public:
        Player * p1;
        Player * p2;
        vector<Ship *> ships;
        Player * next_move;
        Game(Player * p1,Player * p2);
        void makeMove(Player * player,int x,int y);
        virtual ~Game();

    protected:

    private:
};

#endif // GAME_H
