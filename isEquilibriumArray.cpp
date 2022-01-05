#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    int n;cin>>n;
    int arr[n];
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum+=arr[i];
    }

    // O(n2)    
    // for (int i = 0; i < n; i++)
    // {
    //     int left_sum=0,right_sum=0;
    //     for(int j=0;j<i;j++)
    //         left_sum+=arr[j];
    //     for(int j=i+1;j<n;j++)
    //         right_sum+=arr[j];
    //     if(left_sum == right_sum)
    //         cout<<1<<endl;
    // }
    

    //O(n)
    int left_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(left_sum == (sum-arr[i])){
            cout<<1<<endl;
        }
        left_sum+=arr[i];
        sum-=arr[i];
    }
    


    return 0;
}