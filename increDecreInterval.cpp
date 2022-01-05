#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll	              long long int
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define endl "\n"

const long long INF=1e18;
const int32_t MOD = 1e9+7;
const int N = 1e5 + 3;

vector<int> dp(N,-1);

void solve(){
	int n;
	cin >> n;
	n /= 2;
	vector<pair<int,int>> a(n/2);
	for(int i=0; i<n; i++){
		int x,y;
		cin >> x >> y;
		if(x > y) swap(x,y);
		a[i] = make_pair(x,y);
	}
	sort(all(a));
	vector<pair<int,int>> one;
	vector<pair<int,int>> two;
	for(int i=0; i<n; i++){
		if(one.empty() || one.back().second <= a[i].first){
			one.emplace_back(a[i]);
		}
		else if(two.empty() || two.back().second <= a[i].first){
			two.emplace_back(a[i]);
		}
		else{
			puts("-1");
			return;
		}
	}
	for(pair<int,int> interval : one)
		cout << interval.first << " " << interval.second << " ";
	reverse(all(two));
	for(pair<int,int> interval : two)
		cout << interval.second << " " << interval.first << " ";
	puts("");
}

int main(){
	fastio
	int t;cin>>t;
	while(t--)solve();
	return 0;
}