#include<bits/stdc++.h>
using namespace std;

int main(){
    file_i_o();
    int n;cin>>n;
    int a[n];
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    int dp[maxi]={0};
    for(int i=0;i<n;i++){
        dp[a[i]]++;
    }
    int maxe=dp[0];
    for(int i=0;i<maxi;i++){
        maxe=max(maxe,dp[i]);
    }
    cout<<maxe<<endl;
    return 0;
}