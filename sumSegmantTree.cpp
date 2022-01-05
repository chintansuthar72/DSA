#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define f(i,n) for(int i=0; i<n; i++)
#define matin(n, m, mat) for(int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>mat[i][j]
#define pa(n, arr) for(int i=0; i<n; i++) cout<<arr[i]<<' '; cout<<'\n'
const int MOD = 1e9+7;
const int N = 1e5 + 3;
vi dp(N,-1);
// segment tree
// 

vi arr(N),tree(4*N);
void build(int node,int s,int e) {
    if(s==e) {
        tree[node] = arr[s];
        return;
    }   
    int mid = (s+e)/2;
    build(2*node,s,mid);
    build(2*node+1,mid+1,e);

    //
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node,int s,int e,int l,int r) {
    // (s e l r) (l r s e)
    if(e<l || r<s) return 0;
    // (l s e r)
    else if(l<=s && e<=r) {
        return tree[node];
    }
    // (s l e r) (l s r e)
    int mid = (s+e)/2;

    //
    int p1 = query(2*node,s,mid,l,r);
    int p2 = query(2*node+1,mid+1,e,l,r);
    return p1+p2;
}

void solve(int t){
    int n;
    cin >> n;
    f(i,n) cin >> arr[i];

    // Build and Print tree
    build(1,0,n-1);
    // for(int i=1; i<=n; ++i){
    //     cout << tree[i] << " ";
    // }

    // Query in Tree
    while(1) {
        int type;
        cin >> type;
        if(type==-1) break;
        else if(type==1) {
            int l,r; cin >> l >> r;
            cout << query(1,0,n-1,l,r) <<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        solve(t);
    }
    return 0;
}
