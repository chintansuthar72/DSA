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

#define loop(i,a,b) for(int i=a; i<=b; ++i)

bool recurse(vector<vector<char>> grid, string word, int r, int c, int idx, int n) {

    if(idx >= n) return false;
    if(r < 0 || c < 0 || c >= n || r >= n) return false;
    if(grid[r][c] != word[idx]) return false;
    if(idx == n-1) return true;

    grid[r][c] = '$';
    bool retval = false;
    int rows[] = {-1,0,0,1};
    int cols[] = {0,-1,1,0};
    loop(i,0,3){
        retval = recurse(grid, word, r + rows[i], c + cols[i], idx+1, n);
        if(retval) break;
    }

    grid[r][c] = word[idx]; // backtracking
    return retval;
}

bool check(vector<vector<char>> grid, string word, int n) {
    loop(i,0,n-1){
        loop(j,0,n-1){
            if(grid[i][j] == word[0]){
                if(recurse(grid, word, i, j, 0, n)){
                    return true;
                }
            }
        }
    }
    return false;
}


void run_case() {
    int n;
    cin >> n;
    string word;
    cin >> word;
    vector<vector<char>> grid(n,vector<char>(n));
    loop(i,0,n-1){
        loop(j,0,n-1){
            cin >> grid[i][j];
        }
    }
    if(check(grid, word, n)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    clock_t begin = clock();
    #ifndef CHINTAN_DEBUG
        cin.tie(nullptr);
        freopen("in.txt.txt","r",stdin);
    #endif
 
    int tests = 1;
    // cin >> tests;
 
    while (tests--)
        run_case();

    #ifndef CHINTAN_DEBUG
        clock_t end = clock();
        cout << "\nExecuted in: " << double(end-begin)/CLOCKS_PER_SEC*1000 << " ms\n\n";
    #endif

    return 0;
}

// 5
// abhil
// a b c d e
// g h i j k
// f l m n o
// p q r s t
// u v w x y