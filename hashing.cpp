#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// unordered_map
// unordered_set
//  O(1) time complexity

// purpose of hash function is to convert big key into small key that can be used as index of array
// linear chaining - some number(size of array) - modulo operator type - make linear chain or list type 
// open addressing - some number(size of array) - modulo operator type - add into next empty space

int main(){
    
    int arr[] = {1,2,3,6,5};
    unordered_set<int> us;

    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
        us.insert(arr[i]);
    
    cout<<us.size()<<endl;

    if(us.find(7)!=us.end())
        cout<<"Present"<<endl;
    else
        cout<<"Not present"<<endl;

    cout<<*us.find(4)<<endl;
    return 0;
}