#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define loop(a, b, inc) for (int i = a; i <= b; i += inc)
// #define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
#define ll long long int
#define vi vector<int>
#define li list<int>
#define pii pair<int, int>
#define umii unordered_map<int, int>
#define mii map<int, int>
#define qi queue<int>
// using namespace __gnu_pbds;

const int N = 1e3 + 3;
const int MOD = 1e9;


int val[N], wt[N];
int dp[N][N];
int knapsack(int n, int w)
{
    if (w <= 0 or n <= 0)
    {
        return 0;
    }
    if (w - wt[n - 1] < 0)
        return knapsack(n - 1, w);
    return max(knapsack(n - 1, w), knapsack(n - 1, w - wt[n - 1]) + val[n - 1]);
}

int knapsackDp(int n, int w)
{
    for(int i=0; i<=w; i++)
        dp[0][i] = 0;
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=w; j++) {
            if(wt[i-1] > j) {
                dp[i][j] = dp[i-1][j]; 
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-wt[i-1]]+val[i-1]);
            }
        }
    }
    return dp[n+1][w+1];
}

int main()
{
    int n;
    cin >> n;
    loop(0, n - 1, 1)
    {
        cin >> wt[i];
    }
    loop(0, n - 1, 1)
    {
        cin >> val[i];
    }
    int w;
    cin >> w;

    cout << knapsack(n, w) << "\n";
    return 0;
}

// int n,c;
//     cin >> n >> c;
//     int wt[n],val[n];
//     rep(i,0,n) cin >> wt[i] >> val[i];
//     dp[0][wt[0]] = val[0];
//     dp[0][0] = 0;
//     rep(i,1,n){
//         dp[i][0] = 0;
//         rep(j,1,c+1){
// 			dp[i][j] = dp[i-1][j];
// 			if(j >= wt[i])
//             	dp[i][j] = max(dp[i-1][j] , val[i]+dp[i-1][j-wt[i]]);
//         }
//     }
// 	int ans = INT_MIN;
// 	rep(j,0,c+1)
// 		ans = max(ans,dp[n-1][j]);
// 	cout << ans << endl;