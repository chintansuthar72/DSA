#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i;
    cin >> i;
    string str = to_string(i);
    string tmps=str;
    int j=str.length();
    for (int m = 0; m < j; m++,j--)
    {
        int tmp;
        tmp=str[j-1];
        str[j-1]=str[m];
        str[m]=tmp;
    }
    // cout << str << endl;
    (tmps==str)?printf("yes"):printf("no");
    return 0;
}
