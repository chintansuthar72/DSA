// DP problem

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define loop(a, b, inc) for (int i = a; i <= b; i += inc)
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
#define ll long long int
#define vi vector<int>
#define li list<int>
#define pii pair<int, int>
#define umii unordered_map<int, int>
#define mii map<int, int>
#define qi queue<int>
using namespace __gnu_pbds;

// f(0) = 0
// f(1) = 1
// f(2) = 2
// f(3) = 3
// f(4) = 1
// f(5) = 2
// f(6) = 3

int MOD = 1e9 + 7;
vector<int> dp;

int minNumber(int n) // Recursive
{
    if (n == 0 || n == 1 || n == 2 || n == 3)
        return n;

    int ans = INT_MAX;

    for (int i = 1; (i * i) <= n; i++)
    {
        // subAns = min(subAns, 1 + minNumber(n - (i * i)));
        int subAns = minNumber(n - (i * i));
        if (subAns + 1 < ans)
            ans = subAns + 1;
    }

    return ans;
}

int minNumberM(int n) // Memoize
{
    // if (dp[n] != MOD)
    //     return dp[n];

    if (n == 0 || n == 1 || n == 2 || n == 3)
        return dp[n];

    int ans = INT_MAX;
    for (int i = 1; (i * i) <= n; i++)
    {
        // dp[n] = min(dp[n], 1 + minNumberM(n - (i * i)));
        int subAns;
        if (dp[n - (i * i)] != MOD)
            subAns = dp[n - (i * i)];
        else
        {
            subAns = minNumberM(n - (i * i));
            dp[n - (i * i)] = subAns;
        }
        if (subAns + 1 < ans)
            ans = subAns + 1;
    }
    return dp[n] = ans;
}

int minNumberDP(int n)
{
    vector<int> DP(n + 1, MOD);
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 3;

    for (int i = 0; i * i <= n; i++)
    {
        for (int j = 0; (i * i) + j <= n; j++)
        {
            DP[(i * i) + j] = min(DP[(i * i) + j], 1 + DP[j]);
        }
    }

    return DP[n];
}

int main()
{

    int n;
    cin >> n;

    dp = vector<int>(n + 1, MOD);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    cout << minNumberM(n) << "\n";

    return 0;
}