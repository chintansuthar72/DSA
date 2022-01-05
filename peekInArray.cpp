#include<iostream>
#include<climits>
using namespace std;

int idxOfPeekOfArray(int a[],int l,int r,int n){

    int mid = l +(r-l)/2;

    if((mid==0)){
        return mid;
    }

    else if(mid == n-1){
        return mid;
    }

    else if(a[mid-1] <= a[mid] && a[mid] >= a[mid+1]){
        return mid;
    }

    else if(mid > 0 && a[mid] < a[mid-1]){
        return idxOfPeekOfArray(a,l,mid-1,n);
    }

    else{
        return idxOfPeekOfArray(a,mid+1,r,n);
    }
    
    return mid;
}

int main() {

    int a[] = {0,6,8,5,7,6};
    cout << idxOfPeekOfArray(a,0,5,6) << endl;

    return 0;
}