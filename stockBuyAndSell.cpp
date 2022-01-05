#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
    
int main(){
    
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int min = arr[0];
    int maxProfit = 0;

    for(int i=1;i<n;i++){
        if(min > arr[i]){
            min = arr[i];
        }
        if(maxProfit < (arr[i] - min)){
            maxProfit = arr[i] - min;
        }
    }

    cout << maxProfit << endl; 
    return 0;
}