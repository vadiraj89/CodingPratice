#include <bits/stdc++.h>


using namespace std;
int getMinEnergy(vector<int> inp){
    vector<int> dp(inp.size(),0);
    dp[inp.size()-1]=inp[inp.size()-1]>0?1:abs(inp[inp.size()-1])+1;
    for(int i=inp.size()-2;i>=0;i--){
        dp[i]=max(dp[i+1]-inp[i],1);
    }
    
    return dp[0];
}
int main()
{
    int t;
    cin>>t;
    vector<vector<int>> inputs;
    while(t>0){
      int size;
      cin>>size;
      vector<int> input;
      for(int i=0;i<size;i++){
          int inp;
          cin>>inp;
          input.push_back(inp);
      }
      inputs.push_back(input);
      t--;
       
    }
    
    for(auto i:inputs){
       cout<<getMinEnergy(i)<<"\n";
    }

    return 0;
}
