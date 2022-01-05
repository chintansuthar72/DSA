
// set-> random access not possible
// ordered set-> ramdom access possible

// two main funciton - 1) find_by_order(k)= return iterator of kth index(o indexing)
// 2) order_of_key(element)= return index of element

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define oset tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

void file_i_o(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main(){
    file_i_o();
    oset os;
    os.insert(5);
    os.insert(6);
    os.insert(7);
    cout<< *os.find_by_order(1)<< endl;
    cout<< os.order_of_key(7) << endl;
    return 0;
}