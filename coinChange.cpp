#include<iterator>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define f(i,n) for(int i=0; i<n; i++)
#define matin(n, m, mat) for(int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>mat[i][j]
#define pa(n, arr) for(int i=0; i<n; i++) cout<<arr[i]<<' '; cout<<'\n'
const int MOD = 1e9+7;
const int N = 1e3+2;
vi dp(N,-1);
vector<vi> dpTable(N,vi(N,-1));


int funRecusive(int n,vi &arr,int v)
{
    if(v==0) {return 1;}
    else if(n<0) return 0;
    else if(v<0) {return 0;}
    return (funRecusive(n,arr,v-arr[n-1]) + funRecusive(n-1,arr,v));
}
int funMemoize(int n,vi &arr,int v)
{
    if(v==0) {return 1;}
    else if(n<0) return 0;
    else if(v<0) {return 0;}
    if(dpTable[n][v] != -1) return dpTable[n][v];
    dpTable[n][v] = (funMemoize(n,arr,v-arr[n-1]) + funMemoize(n-1,arr,v));
    return dpTable[n][v];
}
int funTabulation(int n,vi &arr,int v)
{
    dp[0] = 1;
    for(int i=1; i<=v; ++i) dp[i] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<v+1; j++){
            if(j>=arr[i]){
                dp[j] = dp[j] + dp[j-arr[i]];
            } 
        }
    }
    return dp[v];
}

void solve(int t){
    // memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    vi arr(n);
    f(i,n) cin >> arr[i];
    int v; cin>>v;
    // cout << funRecusive(n,arr,v);
    // cout << funMemoize(n,arr,v);
    cout << funTabulation(n,arr,v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("./input.txt","r",stdin);
    // freopen("./output.txt","w",stdout);
    int t;
    cin>>t;
    while (t--){
        solve(t);
    }
    return 0;
}
