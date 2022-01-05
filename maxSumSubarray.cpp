#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    //O(n3)
    // int maxSum = 0;
    // for(int i=0; i<n; i++){
    //     for(int j=i; j<n; j++){
    //         int sum = 0;
    //         for(int k=i; k<=j; k++){
    //             sum += arr[k];
    //             // cout << arr[k] << " ";
    //         }
    //         // cout << "\n";
    //         maxSum = max(maxSum,sum);
    //     }
    // }
    // cout << maxSum << endl;

    // O(n2)
    // int maxSum = 0;
    // for(int i=0; i<n; i++){
    //     int sum = 0;
    //     for(int j=i; j<n; j++){
    //         sum += arr[j];
    //         maxSum = max(maxSum,sum);
    //     }
    // }
    // cout << maxSum << endl;

    // O(n) --- kadane's algorithm
    int maxSum = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum < 0) {
            sum = 0;
        }
        maxSum = max(sum,maxSum);
    }
    cout << maxSum << endl;
    return 0;
}