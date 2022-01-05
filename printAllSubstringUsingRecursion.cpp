#include<iostream>

using namespace std;

bool isSafe(string s){
    if(s.length() == 1 || s.length() == 0)
        return true;
    for (int i = 0; i < s.length()-1; i++)
    {
        if(s[i]=='a' and s[i+1]=='b'){
            return false;
        }
    }
    return true;
}

void getAllSubString(string s,string current="",int index=0){
    
    if(index == s.length()){
        if(isSafe(current))
            cout << current << endl;
        return;
    }

    getAllSubString(s,current,index+1);
    getAllSubString(s,current+s[index],index+1);
}

int main(){
    string s;
    getline(cin,s);
    getAllSubString(s);
   
    
    return 0;
}