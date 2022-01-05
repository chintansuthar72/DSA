#include<iostream>
using namespace std;

/*
18 5 
5 3  
3 2  
2 1  
1 0  
*/   

int gcd(int a,int b){ // O(logN) Time complexity
    while (b!=0)
    {
        int r=a%b;
        a=b;
        b=r;   
    }
    return a;
}
int main()
{
    int a,b; cin>>a>>b;
    cout << gcd(a,b);
    return 0;
}
