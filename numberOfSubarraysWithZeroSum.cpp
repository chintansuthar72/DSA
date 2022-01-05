#include<bits/stdc++.h>
using namespace std;

// Count number of subarrays with zero sum

signed main(){
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];
    vector<int> pref(n);
    pref[0] = a[0];
    for(int i=1; i<n; ++i){
        pref[i] = pref[i-1] + a[i];
    }
    // what now
    unordered_map<int,int> freq;
    for(auto sum : pref){
        freq[sum] ++;
    }
    bool ok = false;
    for(auto fre : freq){
        if(fre.second > 0){
            ok = true;
            break;
        }
    }
    if(ok) cout << "Y\n";
    else cout << "N\n";
    return 0;
}
