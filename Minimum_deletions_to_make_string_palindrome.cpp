#include <bits/stdc++.h>

using namespace std;
int getMinDeletions(string s){
    int DP[s.length()][s.length()];
    for(int i=0;i<s.length();i++){
        DP[i][i]=1;
    }
    for(int len=2;len<=s.length();len++){
        for(int i=0;i<s.length()-len+1;i++){
            int j=i+len-1;
            if(s[i]==s[j] && len==2){
                DP[i][j]=2;
            }
            
            else if(s[i]==s[j]){
                DP[i][j]=DP[i+1][j-1]+2;
            }
            
            else{
                DP[i][j]= max(DP[i+1][j],DP[i][j-1]);
            }
        }
    }
    
    return DP[0][s.length()-1];
}
int main()
{
    int t;
    cin>>t;
    vector<string> inp;
    while(t>0){
        string s;
        cin>>s;
        inp.push_back(s);
        t--;
    }
    for(auto i:inp){
        cout<<i.length()-getMinDeletions(i)<<"\n";
    }
  
    return 0;
}
