#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;

    node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class CircularDoublyLinkedList{

    private:
        node* head;

    public:
        CircularDoublyLinkedList(){
            head = nullptr;
        }

        void display_clist(){

            if(head->next == head){
                cout << head->data << "-";
                return;
            }

            cout << head->data << "-";
            node* tmp=head->next;
            while (tmp!=head)
            {
                cout<<tmp->data<<"-";
                tmp=tmp->next;
            }
            cout << "head" << endl;
        }

        void create_list(int value){
            node* n = new node(value);
            head = n;
            head->next = head;
            head->prev = head;
        }

        void insert_begin(int value){

            node* n = new node(value);
            
            node* tmp = head->prev;
            tmp->next = n;
            n->prev = tmp;
            n->next = head;
            head->prev = n;
            head = n;
        }

        void insert_last(int value){
            node* n = new node(value);
            if(!(head->next && head->prev)){
                head->next=n;
                n->prev =head;
                n->next=head;
                head->prev = n;
            }
            node* tmp = head->prev;
            tmp->next = n;
            n->prev = tmp;
            n->next = head;
            head->prev = n;
        }

        void insert_pos(int value, int position){
            node* n = new node(value);
            node* tmp =  head;

            int count = 1;
            while(count != position){
                count++;
                tmp = tmp->next;
            }
            if(tmp->next == head){
                insert_last(value);
                return;
            }
            node* change_node = tmp->next;
            tmp->next =n;
            n->prev = tmp;
            n->next = change_node;
            change_node->prev =n;

        }

        void delete_pos(int position){

            if(position == 1){
                node* helper = head;
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
                delete helper; 
                return;
            }
            int count = 1;
            node* tmp = head;
            while(count != position){
                count++;
                tmp = tmp->next; 
            }
            node* prvptr = tmp->prev;
            node* currptr = tmp;
            node* nxtptr = tmp->next;
            prvptr->next = nxtptr;
            nxtptr->prev = prvptr;
            delete currptr;
        }

        bool search(int value){

            if(head->data == value) return true;
            node* tmp=head->next;
            while (tmp!=head)
            {
                if(tmp->data==value){
                    return true;
                }
                tmp=tmp->next;
            }
            return false;
        }

        void reverse(){

            if((head->next == nullptr) || head==nullptr){
                return;
            }
            node* curr = head;
            node* tmp = nullptr;
            while(1){
                tmp = curr->prev;
                curr->prev = curr->next;
                curr->next = tmp;
                if(curr->prev == head){
                    head = curr;
                    return;
                }
                curr = curr->prev;
            } 
        }

        void sortlist()
        {   
            if(head->data > head->next->data){
                int a = head->data;
                head->data = head->next->data;
                head->next->data = a;
            }
            // bubble sort type
            for(node* temp1=head->next;temp1!=head;temp1=temp1->next)
            {
                for(node* temp2=temp1->next;temp2!=head;temp2=temp2->next)
                { 
                    if(temp2->data < temp1->data)
                    {
                        int a = temp1->data;
                        temp1->data = temp2->data;
                        temp2->data = a;
                    }
                }
            }
        }
};

int main(){
    CircularDoublyLinkedList l;
    l.create_list(7);
    l.insert_begin(1);
    l.display_clist();
//    l.insert_last(6);
//    l.insert_last(5);
//    l.insert_last(4);
//    l.insert_begin(1);
//    l.insert_pos(3,2);
//    l.display_clist();
//
//    while(1){
//        int x;
//        int n;
//        cout << "Enter 1 to insert a new node at the end of the list" << endl;
//        cout << "Enter 2 to delete node at particular position" << endl;
//        cout << "Enter 3 to insert a new node after particular position" << endl;
//        cout << "Enter 4 to sort list" << endl;
//        cout << "Enter 5 to search in list" << endl;
//        cout << "Enter 6 to insert a new node at the front of the list" << endl;
//        cout << "Enter 7 to reverse list" << endl;
//        cout << "Enter 8 to exit program" << endl;
//        cin>>n;
//        if(n==8){
//            cout << "Thanks !!" << endl;
//            break;
//        }
//        switch(n){
//            case 1:
//                cout << "Enter node data : ";
//                cin>>x;
//                l.insert_last(x);
//                cout << "List after operation" << endl;
//                l.display_clist();
//                break;
//
//            case 2:
//                cout << "Enter position : ";
//                cin>>x;
//                l.delete_pos(x);
//                cout << "List after operation" << endl;
//                l.display_clist();
//                break;
//
//            case 3:
//                cout << "Enter data of new node : ";
//                cin>>x;
//                cout << "Enter particular position of node : ";
//                int y;
//                cin>>y;
//                l.insert_pos(x,y);
//                cout << "List after operation" << endl;
//                l.display_clist();
//                break;
//
//            case 4:
//                l.sortlist();
//                cout << "List after operation" << endl;
//                l.display_clist();
//                break;
//
//            case 5:
//                cout << "Enter node data : ";
//                cin>>x;
//                if(l.search(x)){
//                    cout << "Present in list "<< endl;
//                }
//                else{
//                    cout<<"Not present in list"<< endl;
//                }
//                break;
//
//            case 6:
//                cout << "Enter node data : ";
//                cin>>x;
//                l.insert_begin(x);
//                cout << "List after operation" << endl;
//                l.display_clist();
//                break;
//
//            case 7:
//                l.reverse();
//                cout << "List after operation" << endl;
//                l.display_clist();
//                break;
//
//            default:
//                cout << "Enter valid case.." << endl;
//                break;
//        }
//    }
    return 0;
}