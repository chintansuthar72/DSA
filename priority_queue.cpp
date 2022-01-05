// 50 40 30 20 10 -< order like this non increasing order
// pop() , top() , push() , size() , empty() , emplace() , swap() 

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define loop(a,b,inc) for(int i=a;i<=b;i+=inc)
#define oset tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

void file_i_o(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

void printQueue(priority_queue<int> pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

void reversePrint(priority_queue<int,vector<int>,greater<int>> pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

int main(){
    file_i_o();
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(50);
    pq.push(20);
    pq.push(40);
    pq.push(60);
    
    printQueue(pq);
    cout<<pq.top()<<endl;
    pq.pop();
    printQueue(pq);
    cout<<pq.size()<<endl;

    priority_queue<int> cp;
    loop(1,5,1){
        cp.push(i);
    }
    printQueue(cp);
    cp.swap(pq);
    printQueue(cp);
    printQueue(pq);

    priority_queue<int,vector<int>,greater<int>> repq;
    repq.push(10);
    repq.push(30);
    repq.push(50);
    repq.push(20);
    repq.push(40);
    repq.push(60);
    reversePrint(repq);
    return 0;
}