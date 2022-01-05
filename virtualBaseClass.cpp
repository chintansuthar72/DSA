#include<iostream>
using namespace std;


class student{
    protected:
        int roll_no;
    public:
        void set_number(int a){
            roll_no = a;
        }
        void print_number(void){
            cout<<"Your roll no is "<<roll_no<<endl;
        }
};

class test :virtual public student{
    protected : 
        float maths,physics;
    public :
        void set_marks(float m1,float m2){
            maths = m1;
            physics = m2;
        }
        void print_marks(void){
            cout << "maths : "<< maths << endl
                 << "physics : "<< physics << endl;
        }
};

class sports :virtual public student{
    protected :
        float score;
    public :
        void set_score(int sc){
            score = sc;
        }
        void print_score(void){
            cout << "score : " << score << endl;
        }
};

class result : public test,public sports{
    private :
        float total;
    public : 
        void display(void){
            total = maths + physics + score;
            print_number();
            print_marks();
            print_score();
            cout << "Total : " << total << endl;
        }
};
main()
{
    result chintan;
    chintan.set_number(12);   
    chintan.set_marks(96,99);   
    chintan.set_score(95);   
    chintan.display();
    return 0;
}



