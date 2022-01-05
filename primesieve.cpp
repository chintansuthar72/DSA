#include<iostream>
using namespace std;

void sieve(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        arr[i]=0;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = i*i; j <= n; j+=i)
        {
            arr[j]=1;
        }    
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i]==0)
        {
            cout << i << " "; 
        }
    }
}

void file_i_o(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main()
{
    file_i_o();
    int arr[100];
    int n; cin >> n;
    sieve(arr,n);
    return 0;
}
