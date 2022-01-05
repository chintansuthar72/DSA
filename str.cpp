// all about strings 
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    // string str1="chintan";
    // string str2="suthar";
  
    // string str3=str1+" "+str2;

    // str1[3]='m';  //changing character
    // cout<<str1<<endl;
    // cout<<str1[5]<<endl; //showing index
    // cout<<str1.size()<<endl;

    // cout<<str1.append(str2)<<endl;

    // cout<<str1.size()<<endl;
    // cout<<str1.length()<<endl;
    // cout<<str3;

    // string s;
    // cin>>s;
    // cout<<s;
 
    string s;
    // cin>>s;  // this will not work in using space..
    getline(cin,s);
    cout<<s;

    // /* below program wil run without using namespace*/ 
    // std::string greeting = "Hello";
    // std::cout << greeting;

    // char a='a',A='A';
    // // char b=a-A;
    // cout<<a-A;

    // string s1="chintan_suthar";
    // some functions
    // s1.erase(3,4);

    // s1.clear();
    // if(s1.empty()){
    //     cout<<"empty string"<<endl;
    // }

    // s1.insert(7,"chintan");
    // cout<<s1.find("_suthar")<<endl;

    // cout<<s1.substr(7,7)<<endl;
    // cout<<s1<<endl;

    //number to string
    // int i=345;
    // string str1=to_string(i);
    // cout << str1 << endl;
    return 0;
}