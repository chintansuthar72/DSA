#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    //3 6 2 9 5
    //2 3 6 9 5
    //2 3 6 9 5
    //2 3 5 6 9
    for (int i = 1; i < n; i++)
    {
        int key=arr[i];
        int j=i-1;
        while (key<arr[j]  &&  j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
    return 0;
}
