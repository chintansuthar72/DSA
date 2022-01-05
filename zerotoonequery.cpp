#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;cin>>n>>q;
    
    vector<int> arr(n,0);
    while (q--)
    {   
        int l=0,r=0;
        cin>>l>>r;
        arr[l]++;
        if(r+1 < n)
            arr[r+1]--;
    }
    for (int i = 1; i < n; i++)
    {
        arr[i]+=arr[i-1];
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
