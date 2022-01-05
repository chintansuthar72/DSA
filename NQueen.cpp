#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr,int x,int y,int n) {

    // out of bound
    if(x >= n or y >= n) return true;

    // if any row is marked true
    for(int row=0; row<x; row++) {
        if(arr[row][y] == 1) {
            return false;
        }
    }

    // upper left diagonal checking
    int row = x;
    int col = y;

    while(row>=0 and col>=0) {
        if(arr[row][col] == 1) {
            return false;
        }
        row--;
        col--;
    }

    // upper right diagonal checking
    row = x;
    col = y;

    while(row>=0 and col<n) {
        if(arr[row][col] == 1) {
            return false;
        }
        row--;
        col++;
    }

    // if any condition is not false
    return true;
}

bool NQueen(int **arr,int x,int n) {

    if(x>=n) return true;

    // checking column wise
    for(int col=0; col<n; col++) {

        if(isSafe(arr,x,col,n)) {
            arr[x][col] = 1; // marking true

            // going further in row
            if(NQueen(arr,x+1,n)) {
                return true;
            }

            arr[x][col] = 0; // backtracking
        }
    }
    return false;
}


int main(){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int** arr;
    int n;
    cin>>n;

    arr = new int*[n];

    for(int i=0;i<n;i++) {
        arr[i] = new int[n];
        for(int j=0;j<n;j++) {
            arr[i][j] = 0;
        }
    }

    if(NQueen(arr,0,n)) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << arr[i][j] << " ";
            }
            cout<<"\n";
        }
    }

    return 0;
}