#include<iostream>
#include<stack>
using namespace std;


// using 2 stack
// class queue{
//     stack<int> s1;
//     stack<int> s2;

//     public:
    
//     void push(int val) {
//         s1.push(val);
//     }
//     void pop() {
//         if (s1.empty() and s2.empty()) {
//             cout << "empty queue" << endl;
//             return;
//         }
//         while(!s1.empty()) {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         cout << s2.top() << endl;
//         s2.pop();
//     }
//     bool empty() {
//         if(s1.empty() and s2.empty()) return true;
//         else return false;
//     }
// };


// using 1 stack and another function call stack
class queue{
    stack<int> s;

    public:
    
    void push(int val) {
        s.push(val);
    }
    int pop() {
        if (s.empty()) {
            cout << "empty queue" << endl;
            return -1;
        }
        int x = s.top();
        s.pop();
        if(s.empty()) {
            return x;
        }
        int item = pop();
        s.push(x);
        return item;
    }
    bool empty() {
        if(s.empty()) return true;
        else return false;
    }
};

int main() {
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.empty();
    return 0;
}