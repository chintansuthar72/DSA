#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
vector<int> adj[N];
map<int,int> degree; // In degree Count 
vector<int> toposort;
int main() {
    int u,v,n,m;
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        cin >> u >> v;
        adj[u].push_back(v);
        degree[v]++;
    }
    queue<int> q;
    for(int i=1; i<=n; ++i){
        if(degree[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        toposort.push_back(top);
        for(int x : adj[top]) {
            degree[x]--;
            if(degree[x] == 0) q.push(x);
        }
    }
    for(int element : toposort) {
        cout << element << " ";
    } cout << "\n";
    return 0;
}


// Notes :- Only directed Acyclic Graphs has only Topological sort... Why ?? (Order matters in topological sort)
// A->B  in topological sort A must come first before B
// In cyclic graph one can not decide where to start that's why it is not possible in it.