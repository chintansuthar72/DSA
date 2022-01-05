#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll                long long int
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define endl "\n"

const long long INF=1e18;
const int32_t MOD = 1e9+7;
const int N = 1e5 + 5;

vector<int> primes; // Stores primes till n
vector<pair<int,int>> prime_factorizaion[N]; // prime_factorizaion[45] = vector({3,2},{5,1})
vector<bool> composite(N,false) ;// If number if composite or not e.g. composite[45] = true and composite[7] = false
vector<int> largest_prime_factor_of(N,0);

void solve(){
    int n;
    cin >> n;
    for(int i=2; i <= n; ++i){
        if(composite[i]) continue;
        largest_prime_factor_of[i] = i;
        primes.push_back(i);
        for(int j=2*i; j<=n; j += i){
            composite[j] = 1;
            largest_prime_factor_of[j] = i;
        }
    }
    for(int i=2; i<=n; i++){
        int x = i;
        map<int,int> m;
        while(x != 1){
            m[largest_prime_factor_of[x]]++;
            x /= largest_prime_factor_of[x];
        }
        for(auto k : m){
            prime_factorizaion[i].push_back(k);
        }
    }
    for(auto i : prime_factorizaion[n]){
        cout << i.first << "^" << i.second << endl;
    }    
} 

int main(){
    fastio
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}