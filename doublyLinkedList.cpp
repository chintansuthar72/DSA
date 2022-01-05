#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* prv;
    node* next;

    node(int x){
        prv = NULL;
        next = NULL;
        data = x;
    }
};  

void insertAtHead(node* &head,int x){
    node* n = new node(x);
    n->next = head;
    if(head != NULL){
        head->prv = n;
    }
    head = n;
}

void deleteAtHead(node* &head)
{
    node* tmp = head;
    head = head->next;
    head->prv = NULL;
    delete tmp;
}

void deletion(node* &head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* tmp = head;
    int count = 1;
    while(tmp!= NULL && count!=pos){
        tmp=tmp->next;
        count++;
    }   
    tmp->prv->next = tmp->next;
    if(tmp->next!=NULL){
        tmp->next->prv = tmp->prv;
    }
    delete tmp;
  
}

void insertAtTail(node* &head, int x){
    
    if(head == NULL){
        insertAtHead(head,x);
        return;
    }
    node* n=new node(x);
    node* tmp=head;
    while(tmp->next != NULL){
        tmp=tmp->next;
    }
    tmp->next = n;
    n->prv = tmp;
    n->next = NULL;
}

void display(node* &head){
    node* tmp=head;
    while (tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}

int main(){
    
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    insertAtHead(head,0);
    display(head);
    // deletion(head,3);
    deletion(head,1);
    display(head);
    return 0;
}