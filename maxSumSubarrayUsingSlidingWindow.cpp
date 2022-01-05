#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define loop(a,b,inc) for(int i=a;i<=b;i+=inc)
#define oset tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

void file_i_o(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

// sum of k elements
// sum less than x and that would be maximum
// sliding window approach
// first compute sum of 1st k elements and then iterate from kth element to nth element
// add one element and remove one element

int sumK(int a[],int n,int k,int x){
    int sum = 0;
    for(int i=0; i<k; i++){
        sum += a[i];
    }
    int maxSum = INT_MIN;
    if(sum < x)
        maxSum = sum;
    for(int j=k; j<n; j++){
        sum = sum + a[j] - a[j-k];
        if(sum < x)
            maxSum = max(sum,maxSum);
    }

    return maxSum;
}

int main(){
    file_i_o();
    
    int n,k,x;
    cin >> n >> k >> x;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    cout << sumK(a,n,k,x) << endl;

    return 0;
}