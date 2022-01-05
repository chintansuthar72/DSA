#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
    
class node{
    public :
    int data;
    node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};  

void insertAtHead(node* &head,int x){
    node* n = new node(x);

    if(head == NULL){
        n->next = n;
        head = n; 
        return;
    }
    node* tmp = head;
    while (tmp->next != head)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node* &head,int x){

    if(head == NULL){
        insertAtHead(head,x);
        return;
    }
    node* n=new node(x);
    node* tmp=head;

    while (tmp->next != head)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
    n->next = head;
}


void display(node* &head){
    node* tmp  = head;
    do
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    } while (tmp!=head);
    cout<<endl;
}

void deleteAtHead(node* &head){
    node* tmp=head;
    while(tmp->next!=head){
        tmp=tmp->next;
    }
    node* todelete = head;
    tmp->next = head->next;
    head = head->next;
    delete todelete;
}

void deletion(node* &head,int pos){

    if(pos == 1){
        deleteAtHead(head);
        return;
    }

    node* tmp=head;
    int x = 1;
    while(x!=pos-1){
        tmp = tmp->next;
        x++;
    }
    node* todelete = tmp->next;
    tmp->next = tmp->next->next;
    delete todelete;
}

int main(){
    node* Head = NULL;
    insertAtTail(Head,1);   
    insertAtTail(Head,2);   
    insertAtTail(Head,3);   
    insertAtTail(Head,4);   
    insertAtTail(Head,5);   
    display(Head);
    
    // insertAtHead(Head,6);
    // display(Head);
    
    deletion(Head,1);
    display(Head);
    return 0;
}