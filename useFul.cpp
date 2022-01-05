// जय सिया राम
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_map;
// order_of_key (k) : Number of items strictly smaller than k
// find_by_order(k) : K-th element in a set (counting from zero)
// To make it an ordered_multiset, use pairs of (value, time_of_insertion) to distinguish values which are similar
 
typedef long long int ll;
#define int long long int
#define ld long double
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FRE freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PRECISION(x) cout << setprecision(x); cout << fixed;
#define UNIQUE(a) sort( a.begin(), a.end() ); a.erase( unique( a.begin(), a.end() ), a.end() );
// template <typename C> void UNIQUE(vector<C> &v) { sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin()); }
#define debug(x) cout << #x << " is: " << (x) << endl;
#define debug2(x,y) cout << (#x) <<", "<<(#y)<< " are: " << (x) <<", "<<(y)<< endl;
#define debugx(x) cout << #x << " is: " << (x) << endl; exit(0);
#define kickstart(testcase, res) cout << "Case #" << testcase << ": " << res << endl;
#define f(i,n) for(int i=0;i<n;i++)
#define fa(i,a,n) for(int i=a;i<n;i++)
#define loop(i,a, n) for(int i = a; i <= n; i++)
#define loopb(i,a, n) for(int i = a; i >= n; i--)
#define pb push_back
#define pf push_front
#define eb emplace_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define MOD2 998244353
#define INT_INF 1011111111
#define INF 1000111000111000111LL
// comment below line in interactive mode (since endl flushes stdout)
#define endl "\n"
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int MAXN = 2e5+5;
 
/************************************************************************************/
int binpow(int n, int p) {
    int res = 1;
    while (p > 0) {
        if (p & 1) res = res * n;
        n = n * n;
        p >>= 1;
    }
    return res;
}
int power(int n, int p) {
    int res = 1;
    n %= MOD;
    while (p > 0) {
        if (p & 1) res = (res * n) % MOD;
        n = (n * n) % MOD;
        p >>= 1;
    }
    return res;
}
int modInverse(int n, int p) { 
    return power(n, p - 2);
} 
 
int fact[MAXN], inv[MAXN], invfact[MAXN];
void initFactorials() {
    fact[0] = 1;
      for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i * 1LL) % MOD;
    }
 
    //calculate inverses of [1,N] mod p
    inv[1]=1;
    for(int i=2;i<MAXN;i++)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
 
    invfact[0]=1;
    for(int i=1;i<MAXN;i++)invfact[i]=(invfact[i-1]*inv[i])%MOD;
}
// int nCrMod(int n, int r) {
//     if (n < r) return 0;
//     if (r == 0) return 1;
//     int num = fact[n], den = (fact[r] * fact[n-r]) % MOD;
//     int inv = modInverse(den, MOD);
//     return (num * inv) % MOD;
// }
int nCrMod(int n, int r) {
    if (n < r) return 0;
    if (r == 0) return 1;
    int num = fact[n], invden = (invfact[r] * invfact[n-r]) % MOD;
    return (num * invden) % MOD;
}
int binomialCoeff(int n, int k) {
    int res = 1;
    if(k > n - k) k = n - k;
    for(int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
 
/*
Rotate Left by rotL
rotate(v.begin(), v.begin()+rotL, v.end());
Rotate Right by rotR
rotate(v.begin(), v.begin()+ n-rotR, v.end());
*/
/************************************************************************************/
 
const int N = 1e6+5;
int n, m, k;
 
ll st[4*N], lazy[4*N], arr[N];

void build(ll si , ll ss , ll se) {
    if(ss == se) {
        st[si] = arr[ss];
        return;
    }
 
    ll mid = (ss + se)/2;
    build(2*si , ss , mid);
    build(2*si+1 , mid+1 , se);
 
    st[si] = st[2*si] + st[2*si+1];
}

void update(ll si , ll ss , ll se , ll qs, ll qe, ll val) {
    if(lazy[si] != 0){
        ll dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx * (se - ss + 1);

        if(ss != se){
            lazy[2*si] += dx;
            lazy[2*si + 1] += dx;
        }
    }

    if(qe < ss || qs > se) return;

    if(ss >= qs && se <= qe){
        ll dx = (se - ss + 1)*val;
        st[si] += dx;

        if(ss != se){
            lazy[2*si] += val;
            lazy[2*si + 1] += val;
        }
        return;
    }

    ll mid = (ss + se) / 2;
    
    update(2*si, ss, mid, qs, qe, val);
    update(2*si + 1, mid + 1, se, qs, qe, val);

    st[si] = st[2*si] + st[2*si + 1];
}

ll query(ll si , ll ss , ll se , ll qs , ll qe) {
    if(lazy[si] != 0){
        ll dx = lazy[si];
        lazy[si] = 0;
        st[si] += dx * (se - ss + 1);

        if(ss != se){
            lazy[2*si] += dx;
            lazy[2*si + 1] += dx;
        }
    }

    if(qe < ss || qs > se) return 0;
 
    if(ss >= qs && se <= qe) return st[si];
 
    ll mid = (ss + se)/2;
    ll l = query(2*si , ss , mid , qs , qe);
    ll r = query(2*si+1 , mid+1 , se , qs , qe);
    
    return l + r;
}

void solve() {
    int l, r, c, x;
    char ch;
    cin >> n >> m >> c;

    build(1, 1, n);

    update(1, 1, n, 1, n, c);

    while(m--) {
        cin >> ch;
        if(ch == 'Q') {
            cin >> x;
            cout << query(1, 1, n, x, x) << endl;
        } else {
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        }
    }
} 

signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    PRECISION(10);
    // cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}