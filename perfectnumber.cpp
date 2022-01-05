// find k sized subarray with maximum perfect numbers
// perfect number = (sum of all divisor = number self)

#include <iostream>
#include <climits>
#include <vector>
#include <math.h>
using namespace std;

bool isPerfect(int n) {
	int sum = 0;
	for (int i = 0; i < sqrt(n); i++) {
		if(n%i==0){
			sum+=i;
		}
	}
	return (sum == n);
}

int maxPerfects(vector<int> &arr, int k) {
	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (isPerfect(arr[i])) {
			arr[i] = 1;
		}
		arr[i] = 0;
	}
	int maxAns = INT_MIN;
	for (int i = 0; i < k; i++) {
		ans += arr[i];
	}
	for (int i = k; i < arr.size(); i++) {
		ans = ans + arr[i] - arr[i - k];
		maxAns = max(ans, maxAns);
	}
	return maxAns;
}

int main() {
	// int n, k;
	// cin >> n >> k;
	// vector<int> v;
	// for (int i = 0; i < n; i++)
	// 	cin >> v[i];
	// cout << maxPerfects(v, k) << endl;
	cout << isPerfect(100) << endl;
	return 0;
}