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

// you can take either 1 or 2 or 3 move
int main()
{
    // freopen("input_file.txt", "r", stdin);
    int n;
    cin >> n;
    vi dp(n);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cout << dp[n] << endl;
    return 0;
}