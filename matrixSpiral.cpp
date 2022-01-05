#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    int n;cin>>n;
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>mat[i][j];
        }
    }
    int start_row=0;
    int end_row=n-1;
    int start_col=0;
    int end_col=n-1;

    while(start_row<=end_row && start_col<=end_col){
        for(int i=start_col;i<=end_col;i++){
            cout << mat[start_row][i] << " ";
        }
        start_row++;

        for(int i=start_row;i<=end_row;i++){
            cout << mat[i][end_col] << " ";
        }
        end_col--;

        for(int i=end_col;i>=start_col;i--){
            cout << mat[end_row][i] << " ";
        }
        end_row--;

        for(int i=end_row;i>=start_row;i--){
            cout << mat[i][start_col] << " ";
        }
        start_col++;
    }
    return 0;
}