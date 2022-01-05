#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
const int N = 1e5 + 3;

#define lc (x<<1)   // Left Child
#define rc (x<<1)|1 // Right Child

int arr[N],tree[4*N];
// [s,e]
void build(int node,int s,int e) {
    if(s==e) {
        tree[node] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);
    tree[node] = max(tree[2*node],tree[2*node+1]);
}

int query(int node,int s,int e,int l,int r) {
    if(e<l || r<s) {
        return INT_MIN;
    } else if (l<=s and e<=r) {
        return tree[node];
    }
    int mid = (s+e)/2;
    return max(query(2*node,s,mid,l,r),query(2*node+1,mid+1,e,l,r));
}

void update(int node,int s,int e,int idx,int val) {
    if(idx < s or idx > e) return;
    if(s==e) {
        arr[idx] = val;
        tree[node] = arr[idx];
        return;
    }
    int mid = (s+e)/2;
    update(2*node,s,mid,idx,val);
    update(2*node+1,mid+1,e,idx,val);
    tree[node] = max(tree[2*node],tree[2*node+1]);
}

void solve(int t){
    int n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    build(1,0,n-1);

    while(true) {
        int type;
        cin >> type;
        // Query
        if(type==1) {
            int l,r;
            cin >> l >> r;
            cout << query(1,0,n-1,l,r) << endl;
        } 
        else if(type==2){ // Update
            int idx,val; cin >> idx >> val; 
            update(1,0,n-1,idx,val);
            cout << query(1,0,n-1,0,n-1) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("./input.txt","r",stdin);
    // freopen("./output.txt","w",stdout);
    int t;
    cin>>t;
    while (t--){
        solve(t);
    }
    return 0;
}
