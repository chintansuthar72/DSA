#include <bits/stdc++.h>
using namespace std;

struct P
{
	int x,y;
	void read(){
		cin >> x >> y;
	}
	long long operator*(const P& a)const{
		return (long long)x*a.y - (long long)y*a.x;
	}
};

int main() {
	int n;
	cin >> n;
	vector<P> points(n);
	for(P &x: points){
		x.read();
	}
	long long ans = 0;
	for(int i = 0; i<n; ++i){
		ans += points[i]*points[i+1 == n ? 0 : i+1];
	}
	cout << abs(ans)/2 << "\n";
	return 0;
}