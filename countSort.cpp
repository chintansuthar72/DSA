#include<iostream>

using namespace std;

void countSort(int arr[],int n){

    int k=arr[0];
    for (int i = 0; i < n; i++)
    {
        k=max(k,arr[i]);
    }
    // cout << k;
    int count[k]={0};
    for (int i = 0; i <n; i++)
    {
        count[arr[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        count[i]+=count[i-1];
    }

    int output[n];
    for (int i = n-1; i >= 0; i--)
    {
        output[--count[arr[i]]]=arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
            freopen("error.txt","w",stderr);
        #endif

    int arr[9]; //use number less than 10
    for(int i=0;i<9;i++)
        cin >> arr[i];

    countSort(arr,9);
    for (int i = 0; i < 9; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
