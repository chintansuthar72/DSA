

#include<bits/stdc++.h>
using namespace std;
string a,b;
int largest_length = -1;
int n,k;
vector<vector<int>> dp(1e3+3,vector<int>(1e3+3));

set<string> getLCSstrings(int s1,int s2){
    set<string> s;
    if (s1 == 0 || s2 == 0){
        s.insert("");
        return s;
    }
    if(a[s1-1] == b[s2-1]){
        set<string> tmp = getLCSstrings(s1-1,s2-1);
        for (string str : tmp){
            s.insert(str + a[s1 - 1]);
        }
    }
    else{
        if (dp[s1 - 1][s2] >= dp[s1][s2 - 1])
            s = getLCSstrings(s1-1,s2);
        
        if (dp[s1][s2 - 1] >= dp[s1 - 1][s2]){
            set<string> tmp = getLCSstrings(s1,s2-1);
            s.insert(tmp.begin(), tmp.end());
        }
    }
    return s;
}
int main(){
    cin >> n >> k;
    cin >> a >> b;
    for(int i=0; i<=n; i++){
        dp[0][i] = dp[i][0] = 0;
    }
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else if(dp[i-1][j] >= dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    largest_length = dp[n][n];
    if(largest_length == 0){
        cout << -1;
        return 0;
    }
    set<string> result_strings = getLCSstrings(n,n);
    int total_subseqs = result_strings.size();

    if(total_subseqs < k || total_subseqs == 0){
        cout << -1;
    }else{
        vector<int> result;
        for(string str : result_strings){
            result.push_back(stoi(str));
        }
        sort(result.begin(),result.end());
        cout << result[k-1] <<endl;
    }
    return 0;
}
