#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <bits/stdc++.h>

using namespace std;

class Controller
{
    public:
       map<string,vector<string>> graph;
        Controller();
        bool E1errortype(vector<pair<string,string>> vect_pair);
        bool E2errortype(vector<pair<string,string>> vect_pair);

        void Union(map<string,string> & parent,string a, string b);
        bool E3errortype(vector<pair<string,string>> vect_pair);
        bool E4errortype(vector<pair<string,string>> vect_pair);
        bool E5errortype(vector<pair<string,string>> vect_pair);
        virtual ~Controller();

    protected:

    private:
};

#endif // CONTROLLER_H
