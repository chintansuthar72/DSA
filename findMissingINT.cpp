#include<bits/stdc++.h>
using namespace std;

// XOR METHOD
// given array a{1,3} === make b{1,2,3}
// take XOR of all elements of a(result = x1) and b(result = x2) also.
// x1 XOR x2 will give missing element

// you have given 1 to n integers. One integer is missing from this and we have to find this in efficient way 

int main(){
    int n;
    cin>>n;
    int arr[n-1];
    int sum=0;
    for (int i = 0; i < n-1; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    cout<<(n*(n+1)/2)-sum<<endl;
    sort(arr,arr+n);

    return 0;
}