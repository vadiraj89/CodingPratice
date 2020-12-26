#include <bits/stdc++.h>

using namespace std;
int kaden(vector<int> arr){
    int maxsum=INT_MIN;
    int sum = 0;
    int flag =-1;
    for(int i=0;i<arr.size();i++){
        sum = sum+arr[i];
        if(sum<0){
            sum=0;
        }
       else if(sum>maxsum){
            maxsum=sum;
            flag=1;
        }
    }
    if(flag==1){
        return maxsum;
    }
    else{
        int maxans = arr[0];
        for(int i=0;i<arr.size();i++){
            maxans = max(maxans,arr[i]);
        }
        return maxans;
    }
}

int kadenutil(vector<vector<int>> input){
    int m = input.size();
    int n = input[0].size();
    int maxans = INT_MIN;
    
    for(int i=0;i<n;i++){
        vector<int> mat(m,0);
        for(int j=i;j<n;j++){
            
            for(int z=0;z<m;z++){
                mat[z]=mat[z]+input[z][j];
            }
            
            int output = kaden(mat);
            
            if(output>maxans){
                maxans = output;
            }
            
        }
    }
    
    return maxans;
}
int main()
{
    int t;
    cin>>t;
    vector<vector<vector<int>>> inputs;
    while(t>0){
        vector<vector<int>> inp;
        
        int r;
        int c;
        cin>>r;
        cin>>c;
        for(int i=0;i<r;i++){
            vector<int> row;
            for(int j=0;j<c;j++){
                int input;
                cin>>input;
                row.push_back(input);
            }
            
            inp.push_back(row);
        }
        
        inputs.push_back(inp);
        
        t--;
    }
    
    for(auto j:inputs){
        for(auto i:j){
            for(auto m:i){
                cout<<m<<" ";
            }
            cout<<"\n";
        }
        
        cout<<"\n"<<"\n";
    }

    return 0;
}
