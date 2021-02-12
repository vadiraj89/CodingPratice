#include "Controller.h"
#include <bits/stdc++.h>

using namespace std;
Controller::Controller()
{
    this->graph = map<string,vector<string>>();
}

Controller::~Controller()
{
    //dtor
}

bool Controller::E1errortype(vector<pair<string,string>> vect_pair){
    this->graph.clear();
    for(auto i:vect_pair){
        this->graph[i.first].push_back(i.second);
    }
    for(auto i:this->graph){
        if(i.second.size()>2){
            return false;
        }
    }
    return true;
}
bool comp(const pair<string,string> & p1,const pair<string,string> & p2){
    return p1.first<p2.first;
}
bool Controller::E2errortype(vector<pair<string,string>> vect_pair){
    this->graph.clear();
    sort(vect_pair.begin(),vect_pair.end(),comp);
    for(int i=1;i<vect_pair.size();i++){
        if(vect_pair[i-1].first==vect_pair[i].first && vect_pair[i-1].second==vect_pair[i].second){
            return false;
        }
    }
    return true;
}
string Find(map<string,string> & parent,string k){
    if (parent[k] == k)
            return k;


        return Find(parent,parent[k]);
}

void Controller::Union(map<string,string> & parent,string a, string b)
{
        // find the root of the sets in which elements
        // `x` and `y` belongs
        string x = Find(parent,a);
        string y = Find(parent,b);

        parent[x] = y;
}
bool Controller::E3errortype(vector<pair<string,string>> vect_pair){
    this->graph.clear();
    map<string,string> parent;
    for(auto i:vect_pair){
        parent[i.first]=i.first;
        parent[i.second]=i.second;
    }
    for(auto i:vect_pair){
        string x= Find(parent,i.first);
        string y = Find(parent,i.second);
        if(x==y){
            return false;
        }
        else{
            this->Union(parent,x,y);
        }
    }
    return true;
}

bool Controller::E4errortype(vector<pair<string,string>> vect_pair){
    this->graph.clear();
    for(auto i:vect_pair){
        this->graph[i.second].push_back(i.first);
    }
    for(auto i:this->graph){
        if(i.second.size()>1){
            return false;
        }
    }
    return true;
}
void dfs(map<string,vector<string>> graph,map<string,bool> &vis,string u){
    vis[u]=true;
    for(auto i:graph[u]){
        if(vis[i]==false){
            dfs(graph,vis,i);
        }
    }
}
bool Controller::E5errortype(vector<pair<string,string>> vect_pair){
    this->graph.clear();
    int cnt =0;
    map<string,bool> vis;
    for(auto i:vect_pair){
        vis[i.first]=false;
        vis[i.second]=false;
        this->graph[i.first].push_back(i.second);
    }
    for(auto i:vis){
        if(i.second==false){
            dfs(graph,vis,i.first);
            cnt++;
        }
    }
    if(cnt>1){
        return false;
    }
    else{
        return true;
    }

}

