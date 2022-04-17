#include "bits/stdc++.h"
using namespace std;
#define endl "\n"

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef CHINTAN_DEBUG 
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void run_case();
void dfs();
// int dfs(int node,int parent,vector<vector<int>> &tree,vector<int> &dp) {
//     if(dp[node] != INT_MIN) return dp[node];
//     int ans = INT_MIN;
//     for(auto next : tree[node]) {
//         if(next != parent)
//             ans = max(ans, dfs(next,node,tree,dp));
//     }
//     if(ans != INT_MIN)
//         return dp[node] = ans + 1;
//     return dp[node] = 0;
// }

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int tests = 1;
    // cin >> tests;
    for(int i = 1; i<=tests; ++i)
        run_case();
    return 0;
}

// void run_case() {
//     int n;
//     cin >> n;
//     vector<int> dp(n+1,INT_MIN);
//     vector<vector<int>> tree(n+1,vector<int>());
//     int u,v;
//     for(int i = 0; i < n - 1; ++i) {
//         cin >> u >> v;
//         tree[u].push_back(v);
//         tree[v].push_back(u);
//     }
//     dfs(1,-1,tree,dp);
//     for(int i = 1; i <= n; ++i) {
//         cout << dp[i] << " ";
//     }
// }

const int N = 1e5 + 3;
vector<vector<int>> tree(N,vector<int>());
vector<int> toLeaf1(N,0);
vector<int> toLeaf2(N,0);

void dfs(int node, int parent) {
    for(auto next : tree[node]) {
        if(next == parent) continue;
        dfs(next,node);
        if(toLeaf1[node] < toLeaf1[next] + 1) {
            toLeaf2[node] = toLeaf1[node];
            toLeaf1[node] = toLeaf1[next] + 1;
        } else if(toLeaf2[node] < toLeaf1[next] + 1) {
            toLeaf2[node] = toLeaf1[next] + 1;
        }
    }
}

void run_case() {
    int n;
    cin >> n;
    int u,v;
    for(int i=0; i<n-1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1,-1);
    int diameter = -1;
    for(int i = 1; i <= n; ++i) {
        diameter = max(diameter,toLeaf1[i] + toLeaf2[i]);
    }
    cout << diameter << endl;
}




