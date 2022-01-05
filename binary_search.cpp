#include<iostream>
using namespace std;

int binarySearch(int arr[] , int l ,int r, int key){
   if(l<=r){
       int mid = (l+r)/2;
        
        if(key == arr[mid]){
            return mid;
        }
        else if(key > arr[mid]){
            return binarySearch(arr,mid+1,r,key);
        }
        else if(key < arr[mid]){
            return binarySearch(arr,l,mid-1,key);
        }
    }
    return -1;
}
int main()
{

    int n,key;
    
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i] ;
    }
    cin >> key ;
    cout << binarySearch(arr,0,n,key);
    
    return 0;
}