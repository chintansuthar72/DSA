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
// greedy -- only one particular way
// Dynamic Programming -- more than one way and choose one way(answer)

int minCoinRecursive(int coin[], int total, int n)
{
    if (total == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if ((total - coin[i]) >= 0)
        {
            int subAns = minCoinRecursive(coin, total - coin[i], n);
            if ((subAns + 1) < ans)
            {
                ans = subAns + 1;
            }
        }
    }
    return ans;
}

int minCoinDP(int coin[], int total, int n, vector<int> &dp)
{
    dp[0] = 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if ((total - coin[i]) >= 0)
        {
            int subAns = 0;
            if (dp[total - coin[i]] == -1)
            {
                subAns = minCoinDP(coin, total - coin[i], n, dp);
                dp[total - coin[i]] = subAns;
            }
            else
            {
                subAns = dp[total - coin[i]];
            }
            if ((subAns + 1) < ans)
            {
                ans = subAns + 1;
            }
        }
    }
    dp[total] = ans;
    return dp[total];
}

int main()
{
    int total;
    cin >> total;
    int n;
    cin >> n;
    int coin[n];
    loop(0, n - 1, 1)
    {
        cin >> coin[i];
    }
    // cout << minCoinRecursive(coin, total, n) << endl;
    vector<int> dp(total + 1, -1);
    cout << minCoinDP(coin, total, n, dp) << endl;
    for (auto i : dp)
        cout << i << " ";
    return 0;
}