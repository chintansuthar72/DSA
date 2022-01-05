#include<iostream>

using namespace std;

class student{

public :
    string name;
    int age;
    bool gender;

    // student(string s,int a,bool g){ //constructor
    //     name = s;
    //     age = a;
    //     gender = g;

    // }

    student(){
        cout<<"default constructor"<<endl;  //default constructor
    }

    // student(student &&s2){
        
    // }

    void getInfo(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<gender<<endl;
    }

};

int main(){

    // student s1("chintan",17,1);
    // student s2("male",18,1);
    // student s3("female",16,0);
    student s3();
    
    // s1.getInfo();
    // s2.getInfo();
    // s3.getInfo();
    return 0;
}