// // Directed Graph
// #include <bits/stdc++.h>
// using namespace std;

// bool isCycle(int src,vector<vector<int>> &adj, vector<bool> &stack,vector<bool> &visited){
//     stack[src] = 1;
//     if(!visited[src]){
//         visited[src] = 1;
//         for(int i : adj[src]){
//             if(!visited[i] and isCycle(i,adj,stack,visited)){
//                 return true;
//             }
//             if(stack[i])
//                 return true;
//         }
//     }
//     stack[src] = 0;
//     return false;
// }
// int32_t main()
// {
//     int n; // number of vertexs
//     int m; // number of edges
//     cin >> n >> m;
//     vector<vector<int>> adj(n); 
//     vector<bool> visited(n,0);
//     vector<bool> stack(n);

//     for (int i = 0; i < m; ++i)
//     {
//         int u, v;
//         cin >> u >> v; // connection between u and v node
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     bool cycle = false;
//     for(int i=0; i<n; ++i){
//         if(!visited[i] and isCycle(i,adj,stack,visited)){
//             visited[i] = 1;
//             cycle = true;
//         }
//     }

//     if(cycle)
//         printf("Present\n");
//     else
//         printf("Not Present\n");
//     return 0;
// }

// // Undirected Graph Using DFS
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 3;
// int n,m;
// vector<int> adj[N];
// vector<bool> visited(N,false);
// // vector<int> parent(N,-1); // parent vector 

// bool isCycle(int src,int parent){

//     visited[src] = true; // first make visited src

//     // DFS like Travesal and check for all childs for cycle
//     for(auto i : adj[src]){
//         if(i != parent){
//             if(visited[i])
//                 return true;
//             else if(!visited[i] and isCycle(i,src))
//                 return true;
//         }
//     }

//     return false;
// }

// int main(){
//     // n-vertexs   
//     // m-number of edges
//     cin >> n >> m;

//     for(int i = 0; i < m; i++){
//         int u,v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     bool cycle = false;
//     // check all vertexs for cycle 
//     for(int i = 0; i < n; i++){
//         if(!visited[i] and isCycle(i,-1))
//             cycle = true;
//     }

//     if(cycle)
//         cout << "Present\n";
//     else
//         cout << "Not Present\n";
//     return 0;
// }

// Undirected Graph Using DFS
#include <bits/stdc++.h>
using namespace std;

bool isCycle(int src,vector<int> adj[],vector<bool> &visited,vector<int> &parent){

    visited[src] = 1;

    // BFS
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(auto i : adj[x]){
            if(!visited[i]){
                visited[i] = 1;
                q.push(i);
                parent[i] = x;
            }
            else if(parent[x] != i)
                return true;
        }
    }

    return false;
}

int main(){

    int n,m;
    // n-vertexs   
    // m-number of edges
    cin >> n >> m;

    vector<int> adj[n];
    vector<bool> visited(n,false);
    vector<int> parent(n,-1);

    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    // check all vertexs for cycle 
    for(int i = 0; i < n; i++){
        if(!visited[i] and isCycle(i,adj,visited,parent))
            cycle = true;
    }

    if(cycle)
        cout << "Present\n";
    else
        cout << "Not Present\n";
    return 0;
}