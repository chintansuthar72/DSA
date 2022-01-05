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

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
bool bipartite = true;
vector<int> colored; // -1 for not colored, 1 for red color, 0 for blue color

void color(int src, int currentColor)
{
    // visited[src] means visited node,colored[src] != -1 means colored node,colored[src] != currentColor colored but not appropriate color
    if (visited[src] and colored[src] != -1 and colored[src] != currentColor)
    {
        bipartite = false;
        return;
    }
    else if (!visited[src])
    {
        visited[src] = true;
        colored[src] = currentColor;
        for (auto i : adj[src])
            color(i, (currentColor xor 1));
    }
    else
        return; // Not matching Any condition
}

int main()
{
    freopen("input_file.txt", "r", stdin);
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n, false);
    colored = vector<int>(n, -1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            color(i, 0);
    }

    if (bipartite)
        cout << "Possible\n";
    else
        cout << "Not Possible\n";

    return 0;
}