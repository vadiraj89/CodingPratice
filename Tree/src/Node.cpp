#include "Node.h"
#include <bits/stdc++.h>

using namespace std;
Node::Node(string val)
{
    this->value = val;
    this->neighbours = vector<Node *> ();
}

Node::~Node()
{
    //dtor
}
