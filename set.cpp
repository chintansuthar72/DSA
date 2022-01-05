/*
IMP - never contain duplicates
=> two types 
1) set 
IMP - never contain duplicates
    -> ordered set
        = implemented in BST
        = never access of randomly
        = insert,delete,upper bound,lower bound and search O(logN) complexity, print O(NlogN)
        = sorted order
        = use greater<int> to order it in decending order
        = #include<set> header file
    -> unordered set
        = not in sorted order
        = hashing function
        = insert,delete and search O(1) complexity(avg case) and O(logN) in worst case
        = #include<unordered_set> header file
2) multiset
IMP - contain duplicates
    = implemented in BST
    = never access of randomly
    = insert,delete,upper bound,lower bound and search O(logN) complexity, print O(NlogN)
    = sorted order
    = use greater<int> to order it in decending order
    = #include<set> header file
*/

#include<iostream>
#include<set>
using namespace std;

int main() {
    
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(2);
    s.insert(5);
    // // printing set
    // for(auto i : s) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    // reverse printing
    // for(auto i=s.rbegin(); i!=s.rend(); i++) {
    //     cout << *i << " ";
    // }
    // cout << "\n";

    // //size
    // cout << s.size() << endl;
    // // erasing element
    // s.erase(2);
    // s.erase(s.begin());

    // for(auto i : s) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    // cout << s.size() << endl;

    // cout << *s.upper_bound(4) << endl;
    // cout << *s.lower_bound(4) << endl;

    // multiset<int> ms;
    // // insert
    // ms.insert(1);
    // ms.insert(2);
    // ms.insert(3);
    // ms.insert(3);
    // ms.insert(3);
    // ms.insert(4);
    // ms.insert(5);
    // ms.insert(6);
    // // printing
    // for(auto i : ms) {
    //     cout << i << " ";
    // }
    // cout << "\n";
    // // erasing element
    // //ms.erase(3); // delete all occurances of 3
    // ms.erase(ms.find(3)); // delete only one element(3)
    // for(auto i : ms) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    return 0;
}