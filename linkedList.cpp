#include <bits/stdc++.h>
// #include <list>
// #include <iterator>
using namespace std;

class node{
    public :
        int data;
        node* next;
    
    node(int val){
        data = val;
        next = NULL;
    } 
};

void insertHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}

void insertTail(node* &head,int val){

    node* n=new node(val);
    
    if(head==NULL){
        head=n;
        return;
    }
    node* tmp=head;
    while (tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    tmp->next=n;
}

void display(node* head){
    node* tmp=head;
    while (tmp!=NULL)
    {
        cout<<tmp->data<<"->";
        tmp=tmp->next;
    }
    cout << endl;
}

bool search(node* head,int key){
    node* tmp=head;
    while (tmp!=NULL)
    {
        if(tmp->data==key){
            return true;
        }
        tmp=tmp->next;
    }
    return false;
}

int length(node* &head){
    int count=0;
    node* tmp=head;
    while(tmp!=NULL){
        count+=1;
        tmp=tmp->next;
    }
    return count;
}

void middleOfLL(node* head){
//    int n = length(head);
//    int count = (n/2);
//    node* tmp = head;
//    while (count--){
//        tmp = tmp->next;
//    }
//    cout << tmp->data << endl;

    node* slow=head;
    node* fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout << slow->data << endl;
}

node* appendK(node* &head,int x){
    int count=1;
    int l=length(head);
    x=x%l;
    node* newhead=NULL;
    node* newtail=NULL;
    node* tmp=head;
    while(tmp->next!=NULL){
        if(count==l-x){
            newtail = tmp;
        }
        if(count==l-x+1){
            newhead = tmp;
        }
        tmp=tmp->next;
        count++;
    }
    newtail->next=NULL;
    tmp->next = head;
    return newhead;
}

node* reverseK(node* &head,int k){
    // node* prvptr=NULL;
    // node* currptr = head;
    // node* nextptr;
    // int count=0;
    // while(currptr!=NULL && count<k){
    //     nextptr=currptr->next;
    //     currptr->next = prvptr;
    //     prvptr = currptr;
    //     currptr = nextptr;
    //     count++;
    // }
    // if(nextptr!=NULL){
    //     head->next = reverseK(nextptr,k);
    // }
    // return prvptr;


    int count = 1;
    node* prvptr = nullptr;
    node* currptr = head;
    node* nxtptr = nullptr;

    while(count <= k and currptr != nullptr) {
        nxtptr = currptr->next;
        currptr->next = prvptr;
        prvptr = currptr;
        currptr = nxtptr;
        count++;
    }

    if(nxtptr != nullptr) {
        head->next = reverseK(nxtptr,k);
    }

    return prvptr;
}

bool detectCycle(node* &head){
    node* fast = head;
    node* slow = head;
    slow = slow->next;
    fast = fast->next->next;
    while(fast!=NULL && fast->next!=NULL){
        if(fast == slow){
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

void removeCycle(node* &head){
    node* fast = head;
    node* slow = head;
    slow = slow->next;
    fast = fast->next->next;

    while(slow!=fast){
        slow = slow->next;
        fast = fast->next->next;
    } 
    
    fast = head; 
    while(fast->next != slow->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

int main()
{
    node* head=NULL;
    for (int i = 1; i <= 10; i++)
    {
        insertTail(head,i);
    }
    display(head);
    // insertHead(head,5);
    // display(head);
    // cout<<search(head,3);
    // cout<<length(head)<<endl;
    // node* newhead = appendK(head,2);
    // display(newhead);
    // node* newhead=reverseK(head,2);
    // display(newhead);
    // middleOfLL(head);
    // cout << search(head,3) << endl;

    head = reverseK(head,3);
    display(head);
    return 0;
}


// int main(){
//     list<int> li;
//     li.push_back(3);
//     li.push_back(5);
//     li.push_back(4);
//     li.push_back(2);
//     li.push_back(1);
//     list<int>::iterator it;
//     for(it=li.begin();it!= li.end();it++)
//         cout<<*it<<" ";
//     int m=li.front();
//     int n=li.back();
//     cout << m <<" "<<n;
//     return 0;
// }