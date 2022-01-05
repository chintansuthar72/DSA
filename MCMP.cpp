#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {

    int n;
    cin >> n;
    int arr[n];
    n--;
    for(int i=0; i<n+1; ++i) cin >> arr[i];
    int dp[n+1][n+1];
    int s[n+1][n+1];
    for(int i=1; i<=n; ++i) dp[i][i] = 0;
    for(int l=2; l<=n; ++l){
        for(int i=1; i<=(n-l+1); ++i){
            int j=i+l-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<=(j-1); ++k){
                if(dp[i][k]+dp[k+1][j] + arr[i-1]*arr[k]*arr[j] < dp[i][j]){
                    dp[i][j] = dp[i][k]+dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    s[i][j] = k;
                }
            }
        }
    }
    cout << dp[1][n];
    return 0;
}