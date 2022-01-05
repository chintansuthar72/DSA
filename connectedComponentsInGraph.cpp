// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define loop(a, b, inc) for (int i = a; i <= b; i += inc)
// #define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// using namespace std;
// #define vvi vector<vector<int>>
// #define ll long long int
// #define vi vector<int>
// #define li list<int>
// #define pii pair<int, int>
// #define umii unordered_map<int, int>
// #define mii map<int, int>
// #define qi queue<int>
// using namespace __gnu_pbds;

// int n, m;
// vector<vector<int>> adj;
// vector<bool> visited;
// vector<int> comp; // storing size of components

// int get_comp_size(int idx){
//     if(visited[idx]) // already visited 
//         return 0;
    
//     visited[idx] = 1;
//     int cnt = 1; // self connected so initial 1
//     for(int i:adj[idx]){
//         if(!visited[i]){
//             cnt += get_comp_size(i);
//             visited[i] = 1; // make visited
//         }
//     }
//     return cnt;
// }

// int32_t main()
// {
//     cin >> n >> m;
//     adj = vector<vector<int>> (n); // adjcency list
//     visited = vector<bool> (n,0); // visited vector
    
//     // Input
//     for (int i = 0; i < m; ++i){
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     // store components' sizes
//     for(int i=0;i<n;++i){
//         if(!visited[i]){
//             comp.push_back(get_comp_size(i));
//         }
//     }

//     // print componentes' size
//     for(int i : comp)
//         cout << i << " ";
//     cout<<"\n";
//     return 0;
// }


#include<bits/stdc++.h>
#include<string>
#include<iostream>
#define PI  3.141592653589793
#define endl "\n"
#define ll long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb(a) push_back(a)
#define pop() pop_back()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
//rep(i, 0, 10)  OUTPUT: 0 1 2 3 4 5 6 7 8 9 ;
using namespace std;

const long long INF = 1e18;
const int32_t MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n,m;
vector<int> G[N];
vector<bool> used(N,false);
vector<int> comp;
int ans = 0;
void dfs(int v){
    used[v] = true;
    comp.push_back(v);

    for(auto ver : G[v]){
        if(!used[ver])
            dfs(ver);
    }
}

void find_components(){
    for(int i=0; i<n; i++){
        if(!used[i]){
            dfs(i);
            // for(auto ver : comp){
            //     cout << ver << " ";
            // }
            // cout << endl;
            if(comp.size() > 0)
                ans++;
            comp.clear();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll T = 1;
    cin >> T;
    for(int tc = 0; tc < T; tc++)
    {
        cin >> n >> m;
        for(int i=0; i<m; ++i){
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        find_components();
        cout << ans << endl;
    }
    return 0;
}