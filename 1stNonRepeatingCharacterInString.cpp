#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
char fun(string s){
    pair<int , int> count[256]; // count index pair
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i]].second = i;
        count[s[i]].first += 1;
    }
    int res = INT_MAX;
    for (int i = 0; i < 256; i++)
    {   
        if(count[i].first == 1)
            res = min(res,count[i].second);
    }
    return s[res];
}

int main(){
    string s;
    cin>>s;
    cout << fun(s) << endl;
    return 0;
}