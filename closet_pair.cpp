#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int n,k;
vector<string> a;

bool compare(pair<string,string> one,pair<string,string> two){
    if(one.first == two.first){
        return one.second < two.second;
    }
    return one.first < two.first;
}

int dist(pair<string,string> pr){
    int a = 0;
    for(int i=0; i<k; i++){
        if((pr.first)[i] == 'a') a++;
        if((pr.second)[i] == 'a') a--;
    }
    return abs(a);
}

vector<pair<string,string>> minDist(int l,int r){
    if(l == r){
        if(l == 0) l += 1;
        else if(r == n-1) r -=1;
        else l += 1;
        vector<pair<string,string>> answer;
        answer.push_back(make_pair(a[l],a[r]));
        return answer;
    }
    if(r == l+1){
        vector<pair<string,string>> answer;
        answer.push_back(make_pair(a[l],a[l+1]));
        return answer;
    }

    int mid = (l+r)/2;

    vector<pair<string,string>> answer;
    pair<string,string> other_pr = make_pair(a[mid],a[mid+1]);
    vector<pair<string,string>> one = minDist(l,mid);
    vector<pair<string,string>> two = minDist(mid+1,r);
    int one_dist = dist(one[0]);
    int two_dist = dist(two[0]);
    int other_dist = dist(other_pr);

    if(one_dist < two_dist){
        if(other_dist < one_dist){
            answer.push_back(other_pr);
        } else if(other_dist == one_dist){
            for(auto i : one) answer.push_back(i);
            answer.push_back(other_pr);
        } else{
            for(auto i : one) answer.push_back(i);
        }
    }
    else if(one_dist > two_dist){
        if(other_dist < two_dist){
            answer.push_back(other_pr);
        } else if(other_dist == two_dist){
            for(auto i : two) answer.push_back(i);
            answer.push_back(other_pr);
        } else{
            for(auto i : two) answer.push_back(i);
        }
    }else{
        if(other_dist < two_dist){
            answer.push_back(other_pr);
        } else if(other_dist == two_dist){
            for(auto i : two) answer.push_back(i);
            for(auto i : one) answer.push_back(i);
            answer.push_back(other_pr);
        } else{
            for(auto i : two) answer.push_back(i);
            for(auto i : one) answer.push_back(i);
        }
    }
    sort(answer.begin(),answer.end(),compare);
    return answer;
}

int main(){
    cin >> n >> k;
	bool ok = false;
	int i = 0;
	string str;
    while(cin >> str){
		i++;
		int sz = str.length();
		bool is_b_came = false;
		for(int j = 0; j<sz; ++j){
			if(is_b_came and str[j] == 'a') ok = true;
			if(str[j] == 'b') is_b_came = true;
		}
		if(sz != k) ok = true;
        a.push_back(str);
    }
    if(n < 2 || ok || i != n){
        cout << "FAIL\n";
        return 0;
    }
    sort(a.begin(),a.end());
    vector<pair<string,string>> ans = minDist(0,n-1);

	map<pair<string,string>,int> fa;
	for(auto pr : ans){
		if(pr.first != pr.second){
			pair<string,string> dup = make_pair(pr.second,pr.first);
			if(!fa[dup]){
				fa[pr]++;
			}
		} else {
			fa[pr]++;
		}
	}

	for(auto pr : fa) {
		if(pr.second >= 1){
			for(int i=0; i<pr.second; ++i)
				cout << pr.first.first << "\n" << pr.first.second << "\n\n";
		}
	}

    return 0;
}