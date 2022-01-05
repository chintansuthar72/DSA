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

// // Undirected Graph
// const int N = 1e5 + 3;
// vector<int> sizeArray(N, 0);
// vector<int> parent(N);

// void make_set(int x)
// {
//     parent[x] = x;
//     sizeArray[x] = 1;
// }

// int parent_of(int x)
// {
//     if (parent[x] == x)
//         return x;
//     parent[x] = parent_of(parent[x]);
//     return parent[x];
// }

// void union_set(int a, int b)
// {
//     a = parent_of(a);
//     b = parent_of(b);
//     if (a != b)
//     {
//         if (sizeArray[a] > sizeArray[b])
//         {
//             parent[b] = a;
//             sizeArray[a] += sizeArray[b];
//         }
//         else
//         {
//             parent[a] = b;
//             sizeArray[b] += sizeArray[a];
//         }
//     }
// }
// int main()
// {
//     freopen("input_file.txt", "r", stdin);

//     bool cycle = false;
//     for (int i = 0; i < N; i++)
//     {
//         make_set(i); // all are diff sets
//     }
//     int n, m;
//     cin >> n >> m;
//     vector<pii> edges;
//     loop(0, m - 1, 1)
//     {
//         int u, v; // edge between vertexs u and v
//         cin >> u >> v;
//         edges.push_back(make_pair(u, v)); // edges.push_back({u,v});
//     }
//     for (auto i : edges)
//     {
//         int a = i.first;
//         int b = i.second;

//         if (parent_of(a) != parent_of(b))
//         {
//             union_set(a, b); // not in same set then make it
//         }
//         else
//         {
//             cycle = true; // if in same set then cycle exists
//             // break;
//         }
//     }

//     if (cycle)
//         cout << "Cycle exists\n";
//     else
//         cout << "Cycle doesn't exist\n";
//     return 0;
// }
