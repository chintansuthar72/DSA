// DFS in reverse order of DFS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
vector<int> adj[N];
vector<int> adj2[N];
vector<bool> vis(N,false);
vector<bool> vis2(N,false);
int n,m; // n->Nodes, m->Edges
stack<int> L;
vector<int> temp;

void dfs2(int u){
    if(!vis[u]){
        vis[u] = true;
        for(int nei : adj[u]) {
            dfs2(nei);
        }
        L.push(u);
    }
}

void dfs(int u){
    if(!vis2[u]){
        temp.push_back(u);
        vis2[u] = true;
        for(int nei : adj2[u]){
            dfs(nei);
        }
    }
}

int main() {
    cin >> n >> m;
    int u,v;
    int no_of_strongly_connected_components = 0;
    for(int i=0; i<m; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj2[v].push_back(u); // Transpose Graph
    }
    // stack  will give reverse order of DFS or this is topological sort
    dfs2(1);
    // Transpose the graph --> edges will be reversed
    // adj2[i] <-- fill this - TODO // Filled above already
    // Do DFS according stack top order or finishing time
    while(!L.empty()){
        int ele = L.top();
        L.pop();
        if(!vis2[ele]){
            dfs(ele);
            for(auto k : temp){
                cout << k << " ";
            }cout << "\n";
            temp.clear();
            ++no_of_strongly_connected_components;
        }
    }
    cout << "\nno_of_strongly_connected_components : "<< no_of_strongly_connected_components << endl;
    return 0;
}