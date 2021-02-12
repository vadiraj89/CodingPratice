#ifndef NODE_H
#define NODE_H
#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        string value;
        vector<Node *> neighbours;
        Node(string val);
        virtual ~Node();

    protected:

    private:
};

#endif // NODE_H
