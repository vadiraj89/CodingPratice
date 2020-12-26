#include <bits/stdc++.h>

using namespace std;
unordered_map<char,vector<char>> graph;
string ans = "";
vector<int> vis(26, 0);

void dfs(char u){
vis[u - 'a'] = 1;
for(auto v: graph[u]) if (vis[v - 'a'] == 0) dfs(v);
ans.push_back(u);
}

int main()
{
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    for(int i=0;i<words.size()-1;i++){
        for(int j=0;j<min(words[i].size(),words[i+1].size());j++ ){
            if(words[i][j]!=words[i+1][j]){
                graph[words[i][j]].push_back(words[i+1][j]);
                break;
            }
        }
    }
    for(auto u: graph){
        if(vis[u.first - 'a'] == 0) dfs(u.first);
    }
    reverse(ans.begin(), ans.end());
    cout<<ans;
    return 0;
}
