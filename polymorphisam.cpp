#include <iostream>
using namespace std;

class base{

public:
    virtual void print(){
        cout << "base print" << endl;
    }

    virtual void display(){
        cout <<  "base display" << endl;
    }
};

class derived : public base{

public:
    void print(){
        cout << "derived print" << endl;
    }

    void display(){
        cout <<  "derived display" << endl;
    }
};

int main(){

    base *pointer;
    derived obj;
    pointer = &obj;

    pointer->print();
    pointer->display();


    return 0;
}