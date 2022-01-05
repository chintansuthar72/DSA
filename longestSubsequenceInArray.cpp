#include<bits/stdc++.h>
using namespace std;

int main(){
    file_i_o();
    int n,count=0,max=INT_MIN;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if(arr[i] > max) count++; max = arr[i];
    }
    cout << count << endl;
    return 0;
}

