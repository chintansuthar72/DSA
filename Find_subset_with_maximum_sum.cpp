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
    // You are given an array.Find a subset (Print the maximum sum) with maximum sum with no two consecutive element

    cout << "The subset is : ";
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    dp[0] = a[0];
    dp[1] = max(a[0],a[1]);
    dp[2] = max(a[0]+a[2],a[1]);
    if(a[0] + a[2] > a[1]) cout << a[0] << " " << a[2] << " ";
    else cout << a[1] << " ";
    for(int i=3; i<n; i++){
        dp[i] = max(dp[i-1] , (a[i] + dp[i-2])); // This relation make sense all way
        if(dp[i-1] <= (a[i] + dp[i-2]))
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    cout << "The maximum sum is : " << dp[n-1] << endl;
}

int main(){
	fastio
	int t;cin>>t;
	while(t--)solve();
	return 0;
}