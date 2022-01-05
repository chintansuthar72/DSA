#include<iostream>
using namespace std;

class stack{

    int *arr;
    int top=-1;
    int Size;
    public:
        
        stack(int n){
            arr = new int[n];
            Size =n;
        }
        ~stack(){
            delete[] arr;
            cout << "ELETE";
        }
        void push(int x){
            if(top==Size-1){
                printf("stack overflow");
            }
            top++;
            arr[top]=x;
        }
        void pop(){
            if(top==-1){
                printf("nothing to pop");
            }
            top--;
        }
        bool isEmpty(){
            return top==-1;
        }
        bool isFull(){
            return top==Size-1;
        }
        int peek(){
            if(top==-1){
                printf("nothing at top");
                return -1;
            }
            else{
                return arr[top];
            }
        }
        int size(){
            return (top+1);
        }
};
int main()
{
    
    stack s1(10);
    s1.push(1);
    printf("%d\n",s1.peek());
    return 0;
}