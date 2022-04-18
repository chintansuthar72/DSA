#include <bits/stdc++.h>
using namespace std;
#define ll int
const int N = 2e5+3;
vector<vector<ll>> tree(N,vector<ll>());
vector<ll> height(N,0);
vector<ll> dist(N,0);
void dfs(ll node, ll parent) {
    for(auto next : tree[node]) {
        if(next == parent) continue;
        dfs(next,node);
        // height[node] = max(height[node], height[next] + 1);
        height[node] = max(height[node], height[next]);
    }
    height[node] += 1;
}

void dfs_new(ll node, ll parent) {
    ll max1 = 0, max2 = 0;
    for(int next : tree[node]) {
        if(next == parent) continue;
        if(height[next] >= max1) {
            max2 = max1;
            max1 = height[next];
        } else if(height[next] > max2) {
            max2 = height[next];
        }
    }

    for(int next : tree[node]) {
        if(next == parent) continue;
        if(max1 == height[next]) {
            dist[next] = 1 + max(dist[node], 1 + max2);
        } else {
            dist[next] = 1 + max(dist[node], 1 + max1);
        }
        dfs_new(next,node);
    }
}

int main() {
    int n;
    cin >> n;
    int u,v;
    for(int i = 1; i <= n-1; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,0);
    dfs_new(1,0);
    for(int  i = 1; i <= n; ++i) {
        cout << max(dist[i],height[i]) - 1<< " ";
    }
    return 0;
}