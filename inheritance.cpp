#include <iostream>
using namespace std;

class A{

private :
    int prA;
    void fprA(){
            cout << "fprA" << endl;
    }

public :
    int puA;
    void fpuA(){
            cout << "fpuA" << endl;
    }

protected :
    int pA;
    void fpA(){
            cout << "fpA" << endl;
    }

};

// class B{

// private :
//     int prB;
//     void fprB(){
//             cout << "fprB" << endl;
//     }

// public :
//     int puB;
//     void fpuB(){
//             cout << "fpuB" << endl;
//     }

// protected :
//     int pB;
//     void fpB(){
//             cout << "fpB" << endl;
//     }

// };

// class C : public A,public B{

// };    //multiple inheritance

class B : public A{

};

class C : public B{

};           //multipal inheritance

int main(){

    C obj;
    // obj.fprA;
    obj.fpuA();
    // obj.fpA();
    // obj.fprB;
    // obj.fpuB();
    // obj.fpB;
    
    return 0;

}