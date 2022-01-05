#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
vector<int> sizeArray(N, 0);
vector<int> parent(N);

void make_set(int x)
{
    parent[x] = x;
    sizeArray[x] = 1;
}

int parent_of(int x)
{
    if (parent[x] == x)
        return x;
    parent[x] = parent_of(parent[x]);
    return parent[x];
}

void union_set(int a, int b)
{
    a = parent_of(a);
    b = parent_of(b);
    if (a != b)
    {
        if (sizeArray[a] > sizeArray[b])
        {
            parent[b] = a;
            sizeArray[a] += sizeArray[b];
        }
        else
        {
            parent[a] = b;
            sizeArray[b] += sizeArray[a];
        }
    }
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        make_set(i); // all are diff sets
    }
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    int cost = 0;
    for (auto i : edges)
    {
        int w = i[0];
        int u = i[1];
        int v = i[2];

        int x = parent_of(u);
        int y = parent_of(v);

        if (x == y)
            continue;
        else
        {
            cout << u << " " << v << "\n";
            union_set(u, v);
            cost += w;
        }
    }

    cout << cost << endl;
    return 0;
}