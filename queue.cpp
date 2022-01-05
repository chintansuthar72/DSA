#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// #define n 100
// class queue{
//     int* arr;
//     int front;
//     int back;

//     public:
//         queue(){
//             arr = new int[n];
//             front = -1;
//             back = -1;
//         }
//         void push_enqueue(int x){
//             if(front == -1){
//                 front++;
//                 back++;
//                 arr[back]=x;
//             }
//             if((front > back)){
//                 cout << "queue overflow" << endl;
//             }
//             back++;
//             arr[back]=x;
//         }
//         void pop_dequeue(){
//             if((front == -1) || (front > back)){
//                 cout << "empty queue" << endl;
//                 return ;
//             }
//             front++;
//         }
//         int Front(){
//             if(front == -1){
//                 cout << "empty queue" << endl;
//                 return -1;
//             }
//             return arr[front];
//         }
//         bool empty(){
//             return ((front == -1) || (front > back));
//         }
// };

int main(){
    
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.empty() << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.empty() << endl;
    return 0;
}