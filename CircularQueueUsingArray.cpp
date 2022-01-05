#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define loop(a, b, inc) for (int i = a; i <= b; i += inc)
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
#define ll long long int
#define vi vector<int>
#define li list<int>
#define pii pair<int, int>
#define umii unordered_map<int, int>
#define mii map<int, int>
#define qi queue<int>
using namespace __gnu_pbds;

class Queue
{
    int size;
    int *q;
    int rear, front;

public:
    Queue(int s)
    {
        rear = front = -1;
        size = s;
        q = new int[s];
    }
    void push_in(int value)
    {
        if (rear == -1 and front == -1)
        {
            front = 0;
            rear = 0;
            q[rear] = value;
            return;
        }
        if ((front == 0 and rear == (size - 1)) or (((rear + 1) % size) == front))
        {
            cout << "FULL\n";
            return;
        }
        rear = (rear + 1) % size;
        q[rear] = value;
    }
    void pop_out()
    {
        if (rear == -1 and front == -1)
        {
            cout << "EMPTY\n";
            return;
        }
        if (front == rear)
        {
            front = rear = -1;
            return;
        }
        front = (front + 1) % size;
    }
    int peek_element()
    {
        if (rear == -1 and front == -1)
        {
            cout << "EMPTY\n";
            return -1;
        }
        if (front == rear)
        {
            return q[front];
        }
        return q[front];
    }
    void print()
    {
        if (rear == -1 and front == -1)
        {
            cout << "EMPTY\n";
            return;
        }
        if (front == rear)
        {
            cout << q[front] << "\n";
        }
        int itr = front;
        while (itr != rear)
        {
            cout << q[itr] << " ";
            itr = (itr + 1) % size;
        }
        cout << q[rear];
        cout << "\n";
    }
};

int main()
{
    Queue a(5);
    a.push_in(1);
    a.push_in(2);
    a.push_in(3);
    a.push_in(4);
    a.push_in(5);
    a.print();
    cout << a.peek_element();
    cout << "\n";
    a.pop_out();
    a.pop_out();
    a.print();
    cout << a.peek_element() << "\n";
    a.pop_out();
    a.pop_out();
    a.print();
    a.push_in(6);
    a.print();

    return 0;
}