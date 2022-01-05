#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// given two array describe range.. find max frequency of element in that range.    

int frequencyElement(int l[] , int r[] , int n){
    vector<int> arr(1000); // initially all values(all 1000) are zero.
    
    
    for (int i = 0; i < n; i++)
    {
        arr[l[i]]++;
        arr[r[i]+1]--;
    }
    int max = arr[0],res = 0;
    for (int i = 1; i < 1000; i++)
    {
        arr[i]+=arr[i-1];
        if(max < arr[i]){
            max = arr[i];
            res = i;
        }
    }
    return res;
}

int main(){
    int n;cin>>n;
    int l[n],r[n];
    for(int i=0;i<n;i++)
        cin>>l[i];
    for(int i=0;i<n;i++)
        cin>>l[i];
    cout << frequencyElement(l,r,3) << endl;
    return 0;
}