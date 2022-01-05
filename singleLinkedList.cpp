#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;

    node(int val){
        data = val;
        next = nullptr;
    }
};

class singleLinkedList{

    private:
        node* head;
    public:
        singleLinkedList(){
            head = nullptr;
        }

        void display(){
            node* tmp=head;
            while (tmp!=NULL)
            {
                cout<<tmp->data<<"->";
                tmp=tmp->next;
            }
            cout << "NULL" << endl;
        }

        void push(int new_data){
            node* n = new node(new_data);
            node* tmp = head;
            n->next = tmp;
            head = n;
        }

        void append(int new_data){

            node* n = new node(new_data);

            // if there is no node in list
            if(head == nullptr){
                head = n;
                return;
            }

            // if there are nodes in list
            node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = n;
        }

        void insertAfter(int given_data,int new_data){
            node* n = new node(new_data);

            node* tmp = head;

            while(tmp->data != given_data){
                tmp = tmp->next;
            }

            // adding node in-between
            node* change_link = tmp->next;
            tmp->next = n;
            n->next = change_link;
        }

        void deleteLastNode(){
            node* tmp = head;

            while(tmp->next->next != nullptr){
                tmp = tmp->next;
            }
            node* deleteNode = tmp->next->next;
            tmp->next = nullptr;
            delete deleteNode;
        }

        void deleteNode(int given_data){

            node* tmp = head;

            while(tmp->next->data != given_data){
                tmp = tmp->next;
            }
            node* deletenode = tmp->next;
            tmp->next = tmp->next->next;
            delete deletenode;
        }

        bool search(int given_node){
            node* tmp=head;
            while (tmp!=NULL)
            {
                if(tmp->data==given_node){
                    return true;
                }
                tmp=tmp->next;
            }
            return false;
        }

        void sortlist()
        {
            int a;
            node *temp1 = nullptr;
            node *temp2 = nullptr;

            for(temp1=head;temp1!=NULL;temp1=temp1->next)
            {
                for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
                { 
                    if(temp2->data < temp1->data)
                    {
                        a = temp1->data;
                        temp1->data = temp2->data;
                        temp2->data = a;
                    }
                }
            }
        }
};

int main(){
    singleLinkedList l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);
    l.append(6);
    l.append(7);
    cout << "Your current Linked List is : " << endl;
    l.display();
    while(1){
        int x;
        int n;
        cout << "Enter 1 to insert a new node at the end of the list" << endl;
        cout << "Enter 2 to delete Last node" << endl;
        cout << "Enter 3 to delete node of given data" << endl;
        cout << "Enter 4 to insert a new node after given node" << endl;
        cout << "Enter 5 to sort list" << endl;
        cout << "Enter 6 to search in list" << endl;
        cout << "Enter 7 to insert a new node at the front of the list" << endl;
        cout << "Enter 8 to exit program" << endl;
        cin>>n;
        if(n==8){
            cout << "Thanks !!" << endl;
            break;
        }
        switch(n){
            case 1:
                cout << "Enter node data : ";
                cin>>x;
                l.append(x);
                cout << "List after operation" << endl;
                l.display();
                break;
            
            case 2:
                l.deleteLastNode();
                cout << "List after operation" << endl;
                l.display();
                break;

            case 3:
                cout << "Enter node data : ";
                cin>>x;
                l.deleteNode(x);
                cout << "List after operation" << endl;
                l.display();
                break;

            case 4:
                cout << "Enter data of new node : ";
                cin>>x;
                cout << "Enter node data of given node : ";
                int y;
                cin>>y; 
                l.insertAfter(y,x);
                cout << "List after operation" << endl;
                l.display();
                break;

            case 5:
                l.sortlist();
                cout << "List after operation" << endl;
                l.display();
                break;

            case 6:
                cout << "Enter node data : ";
                cin>>x;
                if(l.search(x)){
                    cout << "Present in list "<< endl;
                }
                else{
                    cout<<"Not present in list"<< endl;
                }
                break;

            case 7:
                cout << "Enter node data : ";
                cin>>x;
                l.push(x);
                cout << "List after operation" << endl;
                l.display();
                break;

            default:
                cout << "Enter valid case.." << endl;
                break;
        }
    }
    return 0;
}