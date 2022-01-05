#include<bits/stdc++.h>
using namespace std;

int N = 1e6,n,m;
bool G[N][N];
vector<int> A(N,-1);

void hamiltonian(int k){
    
}

int main(){
    
    cin >> n >> m;
    for(int i=0; i<m; ++i){
        int u,v;
        cin >> u >> v;
        G[u][v] = 1;
        G[v][u] = 1;
    }

    A[0] = 0;
    hamiltonian(1);

    return 0;
}