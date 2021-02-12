#include "Controller.h"
#include <bits/stdc++.h>

using namespace std;
int main()
{
    Controller * c = new Controller();
    vector<pair<string,string>> inp;
    inp.push_back(make_pair("A","B"));
    inp.push_back(make_pair("B","C"));
    inp.push_back(make_pair("F","C"));
    inp.push_back(make_pair("A","F"));
    inp.push_back(make_pair("A","F"));
    inp.push_back(make_pair("D","E"));
    cout << c->E1errortype(inp)<<endl;
    cout << c->E2errortype(inp)<<endl;
    cout << c->E3errortype(inp)<<endl;
    cout << c->E4errortype(inp)<<endl;
    cout << c->E5errortype(inp)<<endl;
    return 0;
}
