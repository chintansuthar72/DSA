#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
void queries(int prefix_sum[],int a,int b){
    if(a!=0){
        cout<<prefix_sum[b]-prefix_sum[a-1]<<endl;    
    }
    else
        cout<<prefix_sum[b]<<endl;
}

int main(){
    int arr[] = {1,2,5,2,6,2,7,4,6,8,9};
    int prefix_sum[sizeof(arr)/sizeof(int)];
    prefix_sum[0] = 0;
    for(int i=1;i<sizeof(arr)/sizeof(int);++i){
        prefix_sum[i]=prefix_sum[i-1]+arr[i];
    }
    queries(prefix_sum,0,2);
    return 0;
}