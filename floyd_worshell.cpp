// Floyd Warshall Algorithm
// We initialize the solution matrix same as the input graph matrix as a first step. Then we update the solution matrix by considering all vertices as an intermediate vertex. The idea is to one by one pick all vertices and updates all shortest paths which include the picked vertex as an intermediate vertex in the shortest path. When we pick vertex number k as an intermediate vertex, we already have considered vertices {0, 1, 2, .. k-1} as intermediate vertices. For every pair (i, j) of the source and destination vertices respectively, there are two possible cases.
// 1) k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is.
// 2) k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j] if dist[i][j] > dist[i][k] + dist[k][j]
// The following figure shows the above optimal substructure property in the all-pairs shortest path problem.

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
    vector<vector<int>> graph = {{0, 5, INF, 10},
                                 {INF, 0, 3, INF},
                                 {INF, INF, 0, 1},
                                 {INF, INF, INF, 0}};
    int n = graph.size();
    int dist[n][n];
    // cout << n << endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]))
                {
                    dist[i][j] = (dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << dist[i][j] << " ";
        cout << "\n";
    }
    return 0;
}