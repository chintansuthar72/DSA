#include<iostream>
using namespace std;

bool isSAfe(int** arr,int x,int y,int n){
    if (x<n && y<n && arr[x][y]==1)
    {
        return true;
    }
    return false;
}

bool rateinmaze(int** arr,int** solArr,int x,int y,int n){

    if (x==(n-1) && y==(n-1))
    {
        solArr[x][y]=1;
        return true;
    }
    
    if (isSAfe(arr,x,y,n))
    {
        solArr[x][y]=1;
        if (rateinmaze(arr,solArr,x+1,y,n))
        {
            return true;
        }
        if (rateinmaze(arr,solArr,x,y+1,n))
        {
            return true;
        }
        
        solArr[x][y]=0;
        return false;
    }
    return false;
}

int main()
{
    int n;cin>>n;
    
    int** arr=new int* [n];
    
    for (int i = 0; i < n; i++)
    {
        arr[i]=new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }

    
    int** solArr=new int*[n];
    for (int i = 0; i < n; i++)
    {
        solArr[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
            solArr[i][j]=0;
        }
    }    
    cout << endl;
    // if (rateinmaze(arr,solArr,0,0,n))
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<solArr[i][j]<<" ";
    //     }cout << endl;
    //     }
    // }

    if (rateinmaze(arr,solArr,0,0,n))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
    return 0;
}
// 5
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1