
#include<iostream>
using namespace std;

class student{
    // int age; // default is private .. not accesible at out side class
    public :
    string name; //class arguments
    char div;
    int age;
    bool gender;

    // void setAge(int agevalue){ // for setting age using function bcoz age is private attribute of class
    //     age = agevalue;
    // }

    void setInfo(){

        cin >> name >> div >> age >> gender;
        // cin >> div;
        // cin >> age;
        // cin >> gender;

    }

    void printInfo(){
        
        cout << name << endl;
        cout << div << endl;
        cout << age << endl;
        cout << gender << endl;

    }
};


int main(){

    student arr[2];
    
    // for (int i = 0; i < 2; i++)
    // {
    //     int agevalue;
    //     cin >> arr[i].name;
    //     cin >> arr[i].div;
    //     cin >> agevalue;
    //     arr[i].setAge(agevalue);
    //     // cin >> arr[i].age;
    //     cin >> arr[i].gender;
    // }

    for (int i = 0; i < 2; i++)// set value using function
    {
        arr[i].setInfo();
    }
    

    /*for (int i = 0; i < 2; i++)
    {
        cout << arr[i].name << endl;
        cout << arr[i].div << endl;
        cout << arr[i].age << endl;
        cout << arr[i].gender << endl;
    }*/ // printing object values method 1

    for (int i = 0; i < 2; i++) // printing using function
    {
        arr[i].printInfo();
    }
    
    return 0;
}