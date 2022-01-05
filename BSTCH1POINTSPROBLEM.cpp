#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int k, int mid){
	int count = 1, start = a[0];

	for(int i=0; i<n; i++){
		if((a[i] - start) >= mid){
			count++;
			start = a[i];
		}
		if(count == k)
			return true;
	}
	return false;
}

int longestMinDist(int a[], int n, int k) {

	sort(a,a+n);

	int ans = INT_MIN, start = a[0], end = a[n-1];

	while(start < end) {
		int mid = (start + end)/2;
		if(isPossible(a,n,k,mid)) {
			start = mid + 1;
			ans = max(ans, mid);
		} else {
			end = mid;
		}
	}

	return ans;
}

int main () {
	int n, k;
	cin >> n >> k;
	int a[n];
	for(int i=0; i<n; ++i)
		cin >> a[i];
	cout << longestMinDist(a, n, k) << "\n";
	return 0;
}