// https://youtu.be/AKKKvZGaG7I ---> 2nd problem

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <string.h>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
 
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
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
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define bitc(n) __builtin_popcount(n)
#define endl "\n"
#define loop(i,a,b) for(int i=a; i<=b; ++i)

int total_edges = 0;

vector<vector<int>> adj(100000);
char colors[100000];

pair<int,int> dfs(int src, int parent = -1){
    int red = (color[src] == 'R');
    int blue = (color[src] == 'B');
    for(auto neib : adj[src]){
        if(neib ! = parent) {
            pair<int,int> ans = dfs(neib, parent);
            if((ans.first == count_red and ans.second == 0) || (ans.first == 0 and ans.second == count_blue)){
                total_edges += 1;
            }
            red += ans.first;
            blue += ans.second;
        }
    }
    return {red,blue};
}

void run_case() {
    // given tree -- remove edge
    // if((red.count() == total_red and blue.count() == 0) or (red.count() == 0 and blue.count() == total_blue))
    int n;
    cin >> n;
    int count_red = 0, count_blue = 0;
    loop(i,0,n-1){
        char color;
        cin >> color;
        colors[i] = color;
        count_blue += (color == 'R');
        count_red += (color == 'B');
    }
    loop(i,1,n-1){
        int x,y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    dfs(0);
    cout << total_edges << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    clock_t begin = clock();
    #ifndef CHINTAN_DEBUG
        cin.tie(nullptr);
        freopen("in.txt.txt","r",stdin);
    #endif
 
    int tests = 1;
    cin >> tests;
 
    while (tests--)
        run_case();

    #ifndef CHINTAN_DEBUG
        clock_t end = clock();
        cout << "\nExecuted in: " << double(end-begin)/CLOCKS_PER_SEC*1000 << " ms\n\n";
    #endif

    return 0;
}