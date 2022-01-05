#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertTail(node *&head, int val)
{

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
}

void display(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    printf("\n");
}

bool search(node *head, int key)
{
    node *tmp = head;
    while (head != NULL)
    {
        if (tmp->data == key)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

node *reverse(node *&head)
{

    node *prvptr = NULL;
    node *curptr = head;
    node *nxtptr;

    while (curptr != NULL)
    {
        nxtptr = curptr->next;
        curptr->next = prvptr;

        prvptr = curptr;
        curptr = nxtptr;
    }
    return prvptr;
}

node *reverseRecursive(node *&head)
{
    node *newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

int main()
{
    node *head = 0; //head=NULL;
    for (int i = 0; i < 5; i++)
    {
        insertTail(head, i);
    }
    display(head);

    node *newhead = reverse(head);
    display(newhead);
    return 0;
}
