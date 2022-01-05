#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define N unsigned(1e5+2) 

int rootN = 0;

struct Q{
    int l,r,idx;
};
Q q[N];

bool compare(Q q1,Q q2){
    // Left idx in same block then sort on the basis of right idx
    if((q1.l/rootN) == (q2.l/rootN)){
        return q1.r/rootN > q2.r/rootN;
    }
    return q1.l/rootN < q2.l/rootN;
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    rootN = sqrtl(n);

    int nq; // No's of Queries
    cin >> nq;
    for(int i=0; i<nq; i++){
        int l,r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    // Offline processing
    sort(q,q+nq,compare);  

    vector<int> ans(nq); // Store the ans of queries
    int curr_l = 0,curr_r = -1,l,r;
    int curr_ans = 0;
    for(int i=0; i<nq; i++){
        // Queries are one based indexed
        l = q[i].l;
        r = q[i].r;
        l--;r--;
        // This part changes as per problem
        while(curr_r < r){
            curr_r++;
            curr_ans += a[curr_r];
        }
        while(curr_l > l){
            curr_l--;
            curr_ans += a[curr_l];
        }
        while(curr_r > r){
            curr_ans -= a[curr_r];
            curr_r--;
        }
        while(curr_l < l){
            curr_ans -= a[curr_l];
            curr_l++;
        }
        ans[q[i].idx] = curr_ans;
    }
    for(auto i : ans) cout << i << endl;
}