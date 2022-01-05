#include<iostream>
#include<queue>
using namespace std;

class stack{

    int n;
    queue<int> q1;
    queue<int> q2;

    public:
    explicit stack() {
        n=0;
    }
    //method 1
    void push(int x) {
        // pushing element into q2
        q2.push(x);
        n++; // increasing size
        // push all elememts of q1 into q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // swaping queue
        queue<int> tmp = q1;
        q1 = q2;
        q2 = tmp;
    }

    int top() {
        return q1.front();
    }

    void pop() {
        if(!q1.empty())
            q1.pop();
            n--; // decreasing size
            return;
        cout << "stack underflow";
        return;
    }

    int size() {
        return n;
    }

    bool empty() {
        return n==0;
    }

    //method 2
    // void push(int val){
    //     q1.push(val);
    //     n++;
    // }

    // void pop(){
    //     if(q1.empty()){
    //         cout << "stack underflow" << endl;
    //         return;
    //     }

    //     while(q1.size() != 1){
    //         q2.push(q1.front());
    //         q1.pop();
    //     }

    //     q1.pop();
    //     queue<int> tmp = q1;
    //     q1 = q2;
    //     q2 = tmp;
    //     n--;
    // }

    // int top(){
    //     if(q1.empty()){
    //         cout << "stack underflow" << endl;
    //         return -1;
    //     }

    //     while(q1.size() != 1){
    //         q2.push(q1.front());
    //         q1.pop();
    //     }

    //     int ans = q1.front();
    //     q2.push(ans);
    //     queue<int> tmp = q1;
    //     q1 = q2;
    //     q2 = tmp;

    //     return ans;
    // }
};

int main() {

    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.top() << endl;
    s.pop();
    cout << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.size() << endl;
    cout << s.empty() << endl;
    return 0;
}