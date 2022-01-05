#include<iostream>
#include<string>
using namespace std;

// 2nd string is called anagram if and only if it is a permutation of 1st string
// example :  1st="gfg" 2nd="ggf" <- anagram
// example : 1st="gfgg" 2nd="ggf" <- not anagram because 1 g is missing

/* logic is to make array of size 256 that all positions are initialized by zero
 then -- and ++ according to  strings.*/

bool isAnagram(string s,string c){
    if(s.length() != c.length()){
        return false;
    }
    else{
        int count[256]={0} ;
        for (int i = 0; i < s.length(); i++)
        {
            count[s[i]]++;
            count[c[i]]--;
        }
        for (int i = 0; i < 256; i++)
        {
            if(count[i]!=0){
                return false;
            }
        }
        return true;
    }
}
int main(){
    
    string input;
    string check;
    cin >> input >> check;
    cout << isAnagram(input,check) << endl;
    return 0;
}