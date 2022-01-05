#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int K = 20;
int st[N][20]; // i,s^j
// interval of (i,i + s^j - 1) -- length of interval is 2^j power of two
// including end points

signed main(){

	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		st[i][0] = a[i];
	}

	// Pre computing
	for(int j=1; j<=K ; j++){
		for(int i=0; i + (1 << j) <= N; ++i){
			st[i][j] = st[i][j-1] + st[i + (1 << (j-1))][j-1];
		}
	}

	int q;
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;

		int sum = 0;
		for(int j = K; j>=0; j--){
			if(r - l + 1 >= (1 << j)){
				sum += st[l][j];
				l += (1<<j);
			}
		}
		cout << sum << endl;
	}

	return 0;
}