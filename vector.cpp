#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    // Initializing vector with array values
    int arr[] = {10, 20, 5, 23 ,42, 20, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);

    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);//  add element in last
    
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] <<" ";
    // }//output vector
    // cout << endl;
    

    // vector<int>::iterator i;
    // for (i = v.begin(); i !=v.end() ; i++) // i<v.end()<---also write
    // {
    //     cout << *i << " ";
    // }// through iterator
    // cout << endl;

    // for(auto element:v){
    //     cout <<element<< " ";
    // }//by auto keyword
    // cout << endl;

    // v.pop_back(); // remove last element

    // for(auto element:v){
    //     cout <<element<< " ";
    // }printf("\n");

    // vector<int> V1(6,50);
    // swap(v,V1);

    // for(auto element : v){
    //     cout << element << " ";
    // }printf("\n");
    // for(auto element : V1){
    //     cout << element << " ";
    // }printf("\n");

    // vector <int>  v2;
    // v2.push_back(56);

    // v2.push_back(234);
    // v2.push_back(89);
    // v2.push_back(65);
    // sort(v2.begin(),v2.end());
    // for(auto i:v2){
    //     cout << i << " ";
    // }

    vector<int> m(5);
    // for(int i =0;i<5;i++){
    for(int i =0;i<m.size();i++){
        cin>>m[i];
        cout<<m[i];
    }// if we know size taking input
    
    for(auto element : m){
        cout << element << " ";
    }

    int helper;
    while(cin>>helper){
        m.push_back(helper);
    }//if we don't know size taking input
    return 0;
}


// vector<int> V(size)
// for(int i =0;i<size;i++){
//     cin>>V[i];
// }


// int helper;
// while(cin>>helper){
//     V.push_back(helper);
// }