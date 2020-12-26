#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s="aa";
string p = "a";
bool answer=false;

void checkpattern(int is,int ip){
    
     
    if(ip>=p.length()){
        if(is>=s.length()){
            answer=true;
            
        }
        return;
    }
    
    if(p[ip]=s[is]){
        checkpattern(is+1,ip+1);
    }
    if(p[ip]=='.'){
        checkpattern(is+1,ip+1);
    }
    if(p[ip]=='*'){
        
        char ipo=p[ip-1];
        for(int i=0;i+is+1<s.length()-1;i++){
            if(s[is+i]==ipo){
                checkpattern(is+i+1,ip+1);
            }
        }
        checkpattern(is+1,ip+1);
        
        
    }
     else{
         checkpattern(is,ip+1);
     }
    
    
    
}

int main()
{
   
   checkpattern(0,0);
   cout<<answer;
   return 0;
}