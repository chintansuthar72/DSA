#include <iostream>
#include <limits.h>
using namespace std;
int main()
{   
    int T;
    cin >> T;
    int arr[3];
    int max=INT_MIN , smax=INT_MIN ;
        int tmp;
    for (int i = 0; i < T; i++)
    {
        cin >> arr[0];
        cin >> arr[1];
        cin >> arr[2];

        for (int i = 0; i < 3; i++)
    {
        
        if (arr[i] > max)
        {
            smax = max ;
            max = arr[i] ;
            
            
        }
        else if (arr[i] > smax)
        {
            smax = arr[i] ;
        }

        
    }
    cout << smax << endl;
 }

    return 0;
}   