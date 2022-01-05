#include <bits/stdc++.h>
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

bool getBIT(int n,int pos){
    return (n & (1 << pos)) != 0;
}

int setBIT(int n,int pos){
    return (n | (1 << pos));
}

int clearBit(int n,int pos){
    return (n ^ (1 << pos));
}

int countOnes(int n){
    int count = 0;
    while(n){
        n = n & (n-1);
        count++;
    }
    return count;
}
// XOR of same number is zero..
int findNonRepeatingElementInArray(int a[],int len){
    int res = 0;
    for(int i=0; i<len; i++){
        res = res ^ a[i];
    }
    return res;
}

bool checkPowerOf2(int n){
    return !(n & (n-1));
}

void printSubsets(int arr[],int n){
    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    file_i_o();
    // cout << (22<<3) << endl; // 22*(2^3)
    // cout << (22>>3) << endl; // 22/(2^3)

    // cout << getBIT(5,0) << endl;
    // cout << getBIT(5,1) << endl;
    // cout << getBIT(5,2) << endl;

    // int n,x;
    // cin >> n >> x;
    // cout << setBIT(n,x) << endl;
    // cout << clearBit(n,x) << endl; 
    // cout << countOnes(n) << endl;
    // int arr[] = {1,2,3,4,5,1,2,3,4};
    // cout << findNonRepeatingElementInArray(arr,9) << endl;

    // cout << checkPowerOf2(4) << endl;
    int arr[] = {1,2,3,4,5};
    printSubsets(arr,5);
    return 0;
}