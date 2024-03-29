#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i]=arr[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i]=arr[m+1+i];
    }
    
    int i=0,j=0,k=l;
    while (i<n1 && j<n2)
    {
        if (a[i]>b[j])
        {
            arr[k]=b[j];
            k++;
            j++;
        }
        if (a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
    } 
    while (i<n1)
    {
        arr[k]=a[i];
            k++;
            i++;
    }
    while (j<n2)
    {
        arr[k]=b[j];
            k++;
            j++;
    } 
}

void mergeSort(int arr[],int l,int r){

    if (l<r)    
    {
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }  
}

int main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    } 
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    return 0;
}