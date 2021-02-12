#include "Ship.h"
#include <bits/stdc++.h>

using namespace std;
Ship::Ship(int x,int y)
{
   this->position = make_pair(x,y);
   this->status="armed";
}

Ship::~Ship()
{
    //dtor
}
