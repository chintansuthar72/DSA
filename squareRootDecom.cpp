#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    int length = sqrtl(n) + 1;
    vector<int> srdc(length,0);
    for(int i=0; i<n; ++i) srdc[i/length] += a[i];

    int q;
    cin >> q;
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        l--;r--;
        int sum_out = 0;
        for(int i=l; i<=r;){
            if(i%length == 0 and (r - i + 1) >= length){
                sum_out += srdc[i/length];
                i += length;
            }
            else{
                sum_out += a[i];
                i++;
            }
        }
        cout << sum_out << endl;
    }
    
    return 0;
}