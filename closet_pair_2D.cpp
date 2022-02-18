#include<bits/stdc++.h>
using namespace std;
struct P{		
	int x,y;
};

long long sq(long long a){
	return a*a;
}

long long distance(const P& a,const P& b){
    return (sq(a.x - b.x) + sq(a.y - b.y));
}

long long smallest_distance(vector<P> points){
	int n = points.size();
	if(n <= 1) return -1;
    if(n == 2){
        return distance(points[0],points[1]);
    }
	vector<P> left = vector<P>(points.begin(),points.begin() + n/2);
	vector<P> right = vector<P>(points.begin() + n/2,points.end());
	long long d1 = smallest_distance(left);
	long long d2 = smallest_distance(right);
	long long d;
	if(d1 == -1 && d2 == -1){
		return smallest_distance(points);
	}
	if(d1 == -1 && d2 != -1)
		d = d2;
	else if(d1 != -1 && d2 == -1)
		d = d1;
	else
		d = min(d1,d2);
    vector<P> stripe;
    P middle = left.back();
    for(P a : left){
		if(sq(a.x -  middle.x) < d)
			stripe.push_back(a);
	}
	for(P b : right){
		if(sq(b.x - middle.x) < d)
			stripe.push_back(b);
	}
    sort(stripe.begin(),stripe.end(),[&](const P& a,const P& b){
		return a.y < b.y;
    });
    for(int i = 0; i < (int) stripe.size(); ++i){
        for(int j = i + 1; j < (int) stripe.size() && sq(stripe[j].y - stripe[i].y) < d; ++j){
            d = min(distance(stripe[j],stripe[i]),d);
        }
    }
    return d;
}

int main(){
    int n;
    cin >> n;
    vector<P> points(n);
    for(int i=0; i<n; ++i){
        cin >> points[i].x >> points[i].y;
    }
	sort(points.begin(),points.end(),[&](const P &a,const P &b){
		return a.x < b.x;
	});
    cout << smallest_distance(points) << endl;
    return 0;	
}
