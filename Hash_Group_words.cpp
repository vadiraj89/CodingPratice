#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;

string getKey (string & str)
{
    int len = str.length ();
    string key = to_string (len) + "#";
    for (int i = 1; i < str.length (); i++)
    {
      if (str[i] >= str[i - 1])
	        key = key + to_string(str[i] - str[i - 1])+"#";
	  else 
            key = key + to_string('z' - str[i - 1] + str[i] - 'a' + 1)+"#";
	}
    return key;
}


int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif 
    vector<string> words ;
    string word;
    while (cin >> word) 
    { 
        words.push_back(word); 
    } 
    unordered_map < string, vector < int >>Hash;
    for (int i = 0; i < words.size(); i++)
    {
        string key = getKey (words[i]);
        Hash[key].push_back (i);
    }
    for (auto it:Hash)
    {
        for (auto v:it.second)
        cout << words[v] << ", ";
	    cout << endl;
    }
   
  return 0;
}
