#include<bits/stdc++.h>
using ll = long long;
using namespace std;


vector<ll> q;
ll maxi = -1;
vector<ll> prime;


vector<ll> get(ll n) {
 	vector<ll> primesInN;
 	vector<bool> isPrime(n+1, true);
 	for (int i = 2; i <= n; ++i) {
 		if (isPrime[i]) {
 			primesInN.push_back(i);
 			for (int j = i*i; j <= n; j += i) {
 				isPrime[j] = false;
 			}
 		}
 	}
 	return primesInN;
}


void test_case(ll n){
	
	for(int i=0; i<maxi;  ++i){
		if(n % prime[i] == 0){
			cout << prime[i] << endl;
			return;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for(int i=0; i<t; ++i){
		ll n;
		cin >> n;
		q.push_back(n);
		maxi = max(maxi,n);
	}
	prime = get(maxi);
	for(int i=0; i<q.size(); ++i){
		test_case(q[i]);
	}

	return 0;
}