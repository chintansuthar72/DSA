#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int

const int INF = 1e18;
const int32_t mod = 1e9 + 7; // To prevent collision use double hash values -> 1e9 + 9, 1e9 + 5 and so on..
const int N = 1e6 + 5;

int add(int a,int b){
    int res = (a+b)%mod;
    if(res < 0){
        res += mod;
    }
    return res;
}

int mul(int a,int b){
    int res = (a*b)%mod;
    if(res < 0)
        res += mod;
    return res;
}

int power(int a,int b){
    
    if(b == 0)
        return 1;
    if(b == 1) return a;

    int ans = power(a,b/2);
    int res = mul(ans,ans);

    if(b & 1)
        res = mul(res,a);
    if(res < 0)
        res += mod;
    return res;
}

int pw[N];
int inv[N];
int h[N]; // Hash function

void preCalc(int base){
    pw[0] = 1;
    for(int i=1; i<N; ++i)
        pw[i] = mul(pw[i-1],base);
    inv[0] = 1;
    for(int i=1; i<N; ++i)
        inv[i] = mul(inv[i-1],power(base,mod-2));
}

// Build hash for string s
void build(string s){
    int n = s.length();
    h[0] = add(s[0] - 'a', 1);
    for(int i=1; i<n; ++i){
        h[i] = add(mul(pw[i],add(s[i]-'a',1)),h[i-1]);
    }
}

// Hash of [x...y] -> substring
int getHash(int x,int y){
    if(x == 0)  return h[y];
    int res = add(h[y], - h[x-1]);
    res = mul(res , inv[x]);
    return res;
}

signed main()
{
    // preCalc(30);
    // string s;
    // cin >> s;
    // build(s);
    // for(int i=0; i<7; i++){
    //     cout << h[i] << "\n";
    // }
    // cout << getHash(0,6) << endl;
    return 0;
}