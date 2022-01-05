// Single source shortest path

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

int main()
{
    freopen("input_file.txt", "r", stdin);

    const int INF = 1e9;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    vector<int> dist(n,INF);

    int src;
    cin >> src;
    dist[src] = 0;

    for (int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    for(int i=0; i<n-1; i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            dist[v] = min(dist[v],w+dist[u]); 
        }
    }

    for(auto i : dist)
        cout << i << " ";

    return 0;
}