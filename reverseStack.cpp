#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &s,int top){
    if(s.empty()){
        s.push(top);
        return;
    }
    int topele=s.top();
    s.pop();
    insertAtBottom(s,top);
    s.push(topele);
}

void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }
    int top=s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,top);
}

int main(int argc, char const *argv[])
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverseStack(s);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.empty()<<endl;
    return 0;
}