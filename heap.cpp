// Heap Discussion
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int>> pq; // min-heap
    pq.push(3);
    pq.push(6);
    pq.push(2);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    return 0;
}