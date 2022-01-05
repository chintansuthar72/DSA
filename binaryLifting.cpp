#include <bits/stdc++.h>
using namespace std;
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define ll long long int
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl "\n"
#define vt vector
#define pb push_back

const long long INF = 1e18;
const int32_t MOD = 1e9 + 7;
const int N = 1e5 + 5;

// LCA(Lowest common ancestor -- Graph(NO cycles)) Queries 1e5
// n => 1e6

const int LOGN = 22; // log2(1e6)

vt<int> adj[N];
// vt<bool> vis(N,false); // We dont need this because this is going to be tree so there is no cycle.

int A[N]; // Value of each Node array (1 base indexing)

int p[N][LOGN]; // [element][i] = 2^i th parent of element 

int value[N][LOGN]; // [element][i] = XOR(0->2^i-1 th parent of element)

int h[N]; // Height array

void dfs(int src, int prv){
    h[src] = h[prv] + 1;
    
    // Making Parent Array
    p[src][0] = prv;
    value[src][0] = A[src];

    for (auto i : adj[src]){
        if ( i != prv ) // Though these are undirected edges
            dfs(i,src);
    }
}

pair<int,int> query(int u,int v){
    int ans = 0;
    if(h[u] < h[v]){ // Make same height by taking u up
        swap(u,v);
    }
    int diff  =  h[u] - h[v];
    rep(i,0,LOGN){
        if(diff & (1 << i)){
            ans = value[u][i] ^ ans;
            u = p[u][i];
        }
    } 
    if(u == v) return {u,ans};
    for(int i = LOGN-1; i>=0; i--){
        if(p[u][i] != p[v][i]){
            ans = ans ^ value[u][i] ^ value[v][i];
            u = p[u][i]; v=p[v][i];
        }
    }
    return {p[v][0],(ans ^ value[u][0] ^ value[v][0])}; 
}

void solve(){
    rep(i,0,N) 
        adj[i].clear();
    int n, u, v, nq;
    cin >> n  >> nq;
    rep(i,1,n+1){
        cin >> A[i];
    } 
    rep(i, 0, n - 1){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);

    rep(i,0,LOGN){
        p[0][i] = 0;
        value[0][i] = 0;
    }

    rep(i,1,LOGN){
        rep(j,1,n+1){
            // 32th parent = 16th parent(16th Parent)
            p[j][i] = p[p[j][i-1]][i-1];
            value[j][i] = value[j][i-1] ^ value[p[j][i-1]][i-1];
        }
    }

    rep(i, 0, nq){
        cin >> u >> v;
        pair<int,int> ans = query(u, v);
        cout << (A[ans.first] ^ ans.second) << endl;
    }
}

int main()
{
    fastio
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}