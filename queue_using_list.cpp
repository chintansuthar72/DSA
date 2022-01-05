#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
// class node{
//     public:
//     int data;
//     node* next;

//     node(int x){
//         data = x;
//         next = NULL;
//     }
// };

// class queue{
//     node* front;
//     node* back;

//     public:
//         queue(){
//             front = NULL;
//             back = NULL;
//         }
//         void push(int x){
//             if (front == NULL){
//                 node* n = new node(x);
//                 front = n;
//                 back = n;
//                 return;
//             }
//             node* n = new node(x);
//             back->next = n;
//             back = n;
//         }
//         void pop(){
//             if(front == NULL){
//                 cout << "empty queue" << endl;
//                 return;
//             }
//             node* tmp = front;
//             front = front->next;
//             delete tmp;
//         }
//         int top(){
//             if(front == NULL){
//                 return -1;
//             }
//             return (front->data);
//         }
//         bool empty(){
//             if(front == NULL){
//                 return true;
//             }
//             return false;
//         }
// };

int main(){
    
    queue<int> q;
    q.push(4);
    cout << q.front() << endl;

    // queue q;
    // q.push(4);
    // q.push(3);
    // q.push(2);
    // q.push(1);
    // cout << q.top() << endl;
    // q.pop();
    // cout << q.top() << endl;
    // q.pop();
    // cout << q.top() << endl;
    // q.pop();
    // cout << q.top() << endl;
    // q.pop();
    // cout << q.empty() << endl;

    return 0;
}