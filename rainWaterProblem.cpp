#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int left[n];
    left[0] = arr[0];
    
    int right[n];
    right[n-1] = arr[n-1];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1],arr[i]);
    }

    for (int i = n-2; i>=0; i--)
    {
        right[i] = max(right[i+1],arr[i]);
    }

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if((left[i] < right[i]) && ((left[i] - arr[i]) >= 0)){
            total+=(left[i] - arr[i]);
        }
        else if((left[i] > right[i]) && ((right[i] - arr[i]) >= 0)){
            total+=(right[i] - arr[i]);
        }
    }
    
    cout << total << endl;
    return 0;
}