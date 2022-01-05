#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;
#define endl "\n"
#define ff first
#define ss second
#define pb push_back
#define all(x) ((x).begin(),(x).end())
#define FOR(it,first,last) for(int it = first; it < last; ++it)

void solve(){
    int n;
    cin >> n;
    int a[n+1] = {0};
    for(int i=2; i<=n; ++i){
        if(a[i] == 0){
            for(int j = i*i; j <= n; j += i){
                a[j] = i;
            }
        }
    }
    for(int i=2; i<=n; ++i){
        if(a[i]==0)
            a[i] = i;
    }
    set<int> factors;
    while(n > 1){
        factors.insert(a[n]);
        n /= a[n];
    }
    for(auto factor : factors){
        cout << factor << " ";
    }cout << endl;
}

int main() {
	int t=1;
	// cin >> t;
	while(t--){
		solve();
	}
}
