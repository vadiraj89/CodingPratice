#ifndef PLAYER_H
#define PLAYER_H
#include "Ship.h"
#include <bits/stdc++.h>

using namespace std;

class Player
{
    public:
        string pid;
        string fid;
        vector<Ship *> ships;
        Player(string pid,string fid,vector<Ship *> sh);
        virtual ~Player();
        int  tryHit(pair<int,int> pos);
    protected:

    private:
};

#endif // PLAYER_H
