#include<iostream>
// #include<cmath>
using namespace std;
void selectionSort(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i]>arr[j])
            {
                int tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int n;cin >>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);
    return 0;
}
