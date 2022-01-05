#include<iostream>
// #include<bits/stdc++.h>
using namespace std;

void cycleSort(int arr[],int n){
    for(int cs=0;cs<n;cs++){
        int item = arr[cs];
        int pos = cs;
        for(int i=cs+1;i<n;i++){
            if(arr[i] < item){
                pos++;
            }
        }
        if(pos == cs){
            continue;
        }
        while(item == arr[pos]){
            pos+=1;
        }
        int tmp=item;
        item = arr[pos];
        arr[pos] = tmp;

        while(pos!=cs){
            pos = cs;
            for(int i=cs+1;i<n;i++){
                if(arr[i] < item){
                    pos++;
                }
            }
            while(item==arr[pos]){
                pos++;
            }
            int tmp1=item;
            item = arr[pos];
            arr[pos] = tmp1;
        }
    }
}

int main(){
    int n;cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cycleSort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}