#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll                long long
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define endl              "\n"

const long long INF = 1e18;
const int32_t MOD = 1e9+7;
const ll N = 1e5 + 5;

void solve(){
    int a,b;
    cin >> a >> b;
    
    int pre_xor = 0;
    if(a%4 == 1) pre_xor = a-1;
    else if(a%4 == 2) pre_xor = 1;
    else if(a%4 == 3) pre_xor = a;
    else pre_xor = 0;

    if(pre_xor == b) cout << a << "\n";
    else if((pre_xor ^ b) != a) cout << a + 1 << endl;
    else cout << a + 2 << endl;
}

int main(){
    fastio
    ll t=1;cin>>t; while(t--) {solve();}
    return 0;
}