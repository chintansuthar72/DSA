#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string,int> marks;
    marks["chintan"]=50;
    marks["abcd"]=100;
    map<string,int> :: iterator i;
    for(i=marks.begin();i!=marks.end();i++){
        cout<<(*i).first<<" "<<(*i).second<<endl;
    }
    // cout<<marks.empty()<<endl;
    
    return 0;
}