#ifndef SHIP_H
#define SHIP_H

#include <bits/stdc++.h>

using namespace std;
class Ship
{
    public:
        pair<int,int> position;
        string status;
        Ship(int x,int y);
        virtual ~Ship();

    protected:

    private:
};

#endif // SHIP_H
