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

// sorted in ascending order and rotated at any point that is pivot
// find pivot and apply binary search on both array side

// 30 40 50 10 20 <- return 3

int searchInArray(int a[],int n,int key,int l,int r){
    if(l > r){
        return -1;
    }

    int mid = (l+r)/2;

    if(a[mid] == key) return mid;
    
    if(a[l] <= a[mid]){
        if(key >= a[l] && key <= a[mid]){
            return searchInArray(a,n,key,l,mid-1);
        }
        return searchInArray(a,n,key,mid+1,r);
    }

    if(key >= a[mid] && key <= a[r]){
        return searchInArray(a,n,key,mid+1,r);
    }
    return searchInArray(a,n,key,l,mid-1);
}

int main(){
    file_i_o();
    int n,key;
    cin >> n >> key;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << "Idx is : " << searchInArray(a,n,key,0,n-1) << endl;
    return 0;
}