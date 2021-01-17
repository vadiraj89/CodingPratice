// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void generateBinaryNumbers(int n){
    cout<<"Binary Numbers from 1 to "<<n<<"\n";
    queue<string> q;
    q.push("1");
    int count = 1;
    while(count<=n){
        string u = q.front();
        cout<<u<<"\n";
        q.pop();
        q.push(u+"0");
        q.push(u+"1");
        count++;
    }
}
int main() {
   generateBinaryNumbers(15);

}