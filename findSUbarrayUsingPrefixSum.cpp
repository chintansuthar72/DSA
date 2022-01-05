#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// -5 5 6   x=0
//  0  0
// -5  0 -5
//  0  
bool isExist(int* arr,int n,int x){
    unordered_set<int> us;
    int pre_sum = 0;
    us.insert(0);
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if(us.find(pre_sum-x)!=us.end()){
            return true;
        }
        us.insert(pre_sum);
    }
    return false;
}    

int main(){

    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int key;cin>>key;
    cout << isExist(arr,n,key) << endl;
    return 0;
}
