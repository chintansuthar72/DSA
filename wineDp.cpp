#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

const long long INF = 1e18;
const int32_t MOD = 1e9 + 7;
const int N = 1e5 + 5;


void test_cases(){
    int n;
    cin >> n;
    int p[n];

    for(int i=0; i<n; ++i){
        cin >> p[i];
    }

    int dp[n][n] = {0}; // L,R

    for(int i=0; i<n; i++){
        dp[i][i] = n*p[i];
    }

    for(int L= n-1; L >= 0; L--){
        for(int R = 0; R < n; R++){
            int Y = n - R + L;
            if(L != R)
                dp[L][R] = max(dp[L+1][R] + Y*p[L], dp[L][R-1] + Y*p[R]);
        }
    }

    printf("%d\n",dp[0][n-1]);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    // int t;cin>>t;
    // while(t--)
        test_cases();
    return 0;
}