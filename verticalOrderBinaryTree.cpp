#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

unordered_map<int,vector<int>> vertical; // dist,array
void order(int i, int dist, vector<int>& tree){
	if(i >= (int) tree.size()){
		return;
	}
	vertical[dist].push_back(tree[i]);
	order(2*i + 1, dist-1, tree);
	order(2*i + 2, dist+1, tree);
}

int main() {
	int n;
	cin >> n;
	vector<int> tree(n);
	for(int i=0; i<n; ++i){
		cin >> tree[i];
	}
	
	// code from here
	//unordered_map<int,vector<int>> dist;
	//dist[0].push_back(tree[0]);
	//int d = 1;
	//int i = 0;
	//while(i < n){
		//dist[d].push_back(tree[2*i + 2]);
		//i = 2*i + 2;
		//d++;
	//}
	
	order(0,0,tree);
	int maxi = -100000, mini = 100000;
	for(auto p: vertical){
		maxi = max(maxi,p.first);
		mini = min(mini,p.first);
	}
	for(int j = mini; j<=maxi; ++j){
		for(int i=0; i < (int)vertical[j].size(); ++i){
			cout << vertical[j][i] << " ";
		}
	}
	cout << endl;
}
