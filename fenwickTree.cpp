#include<bits/stdc++.h>
using namespace std;
#define vi 				  vector<int>
#define pa(n, arr)        for(int i=0; i<n; i++) cout<<arr[i]<<' '; cout<<'\n'
#define ll                long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t MOD = 1e9+7;
const int N = 1e5 + 3;
vi dp(N,-1);

// 1.Point Update and Range Query - default
// 2.Range Update and Point Query
// 3.Range Update and Range Query

class fenwick_tree{
	ll n;
	vector<ll> bit; // Binary Indexed Tree - Fenwick Tree
public:
	fenwick_tree(ll n){
		this->n = n;
		bit = vector<ll>(n,0);
	}
	ll query(ll idx){
		ll sum = 0; // r=(r&(r+1))-1 and idx -= idx & (-idx)
		for( ;idx > 0; idx -= idx & (-idx)) sum += bit[idx];
		return sum;
	}
	void update(ll idx,ll val){ // idx=(idx|(idx+1)) and idx += idx & (-idx)
		for( ;idx < n; idx += idx & (-idx)) bit[idx] += val;
	}
};


void solve(){
	ll n,m,c;
	cin >> n >> m >> c;
	fenwick_tree bit(n+1);
	while(m--){
		char type;
		cin>>type;
		if(type == 'S'){
			ll l,r,k;
			cin >> l >> r >> k;
			bit.update(l,k);
			bit.update(r+1,-k);
		}else if(type == 'Q'){
			ll i; cin >> i;
			cout << bit.query(i)+c << "\n";
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	// int t=1;
	// cin>>t;
	// while(t--) 
		solve();
	return 0;
}