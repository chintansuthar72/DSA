#include<bits/stdc++.h>
using namespace std;
#define vi 				  vector<int>
#define pa(n, arr)        for(int i=0; i<n; i++) cout<<arr[i]<<' '; cout<<'\n'
#define ll                long long int
#define lld               long long double
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)

void helper(int r,int c,map<pair<int,int>,map<int,int>> &mp,vector<map<int,int>> &row,vector<map<int,int>> &col,vector<vector<int>> &v){
	if(r == 9){								
		for(int i=0; i<9; ++i){
			for(int j=0; j<9; ++j){
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
		return;
	}
		
	if(c == 9){
		helper(r+1,0,mp,row,col,v);
		return;
	}

	if(v[r][c] != 0){
		helper(r,c+1,mp,row,col,v);
		return;
	}

	for(int i=1; i<=9; i++){
		if(mp[{r/3,c/3}][i] != 1 && row[r][i] != 1 && col[c][i] != 1){
			v[r][c] = i;
			mp[{r/3,c/3}][i] = 1;
			row[r][i] = 1; 
			col[c][i] = 1;
			helper(r,c+1,mp,row,col,v);
			// Backtrack
			v[r][c] = 0;
			mp[{r/3,c/3}][i] = 0;
			row[r][i] = 0; 
			col[c][i] = 0;
		}
	}
}

void solve(){
	vector<vector<int>> v = 
	{
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0}
	};

	// Actual Code
	map<pair<int,int>,map<int,int>> mp;
	vector<map<int,int>> row(9);
	vector<map<int,int>> col(9);

	for(int i=0; i<9; ++i){
		for(int j=0; j<9; ++j){
			if(v[i][j] != 0){
				mp[{i/3,j/3}][v[i][j]] = 1;
				row[i][v[i][j]] = 1;
				col[j][v[i][j]] = 1;				
			}
		}
	}
	helper(0,0,mp,row,col,v);
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	solve();
	return 0;
}