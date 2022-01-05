#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
    int tmp=arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void waveSort(int arr[] , int n){
    for (int i = 1; i < (n-1); i+=2)
    {
        if (arr[i] > arr[i-1])
        {
            swap(arr,i,i-1);
        }
        if (arr[i] > arr[i+1])
        {
            swap(arr,i,i+1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n; cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    waveSort(arr,n);    
    return 0;
}
