#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll                long long
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define rep(i,a,b)        for(ll i=a;i<b;i++)
#define endl "\n"

const long long INF=1e18;
const int32_t MOD = 1e9+7;
const ll N = 1e5 + 5;

vector<vector<int>> A = {{1,1},{1,0}};

vector<vector<int>> multiply(vector<vector<int>> &a,vector<vector<int>> &b){
    vector<vector<int>> ans = {{0,0},{0,0}};
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                ans[i][j] += (a[i][k]*b[i][k]);
            }
        }
    }
    return ans;
}

vector<vector<int>> matrixExpo(int n){
    if(n == 0){
        vector<vector<int>> temp = {{1,0},{0,1}};
        return temp;
    }
    if(n == 1){
        return A;
    }
    vector<vector<int>> ans = matrixExpo(n/2);
    ans = multiply(ans,ans);
    if( n & 1 ){
        ans = multiply(ans,A);
    }
    return ans;
} 
// 1 1 2 3 5 8 13 21 34 55
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> B = matrixExpo(n-2);
    cout << "f(n) = " << B[0][0] + B[0][1] << endl;
    cout << "f(n-1) = " << B[1][0] + B[1][1] << endl;
} 

int main(){
    fastio
    ll t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}