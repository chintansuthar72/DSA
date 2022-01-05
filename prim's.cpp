// for minimum spanning tree
// always find minimum edge from till now connected vertexs
// Running Time :- O(V) + O(2E) / O(VE) ---> depends on data structure
#include <bits/stdc++.h>
#define loop(a, b, inc) for (int i = a; i <= b; i += inc)
using namespace std;
#define ll long long int
 

int main()
{
    int cost = 0;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    loop(0, m - 1, 1)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    const int INF = 1e9;
    vector<int> dist(n, INF);
    vector<int> parent(n, 0);
    int source = 0;
    dist[source] = 0;

    set<pair<int, int>> s;
    s.insert({dist[source], source}); // dist,vertex

    vector<bool> visited(n, false);
    while (!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        int u = x.second;
        int w = x.first;
        int v = parent[u];
        visited[u] = true;

        cout << u << " " << v << " " << w << endl;
        cost += w;

        for (auto i : adj[u])
        {
            if (visited[i.second])
                continue;
            if (dist[i.second] > i.first)
            {
                s.erase({dist[i.second], i.second});
                dist[i.second] = i.first;
                s.insert({dist[i.second], i.second});
                parent[i.second] = u;
            }
        }
    }

    cout << cost << endl;
    return 0;
}