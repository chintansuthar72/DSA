#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

// Sum of Two number
string sumup(string a, string b) {

    int sa = a.size(), sb = b.size();
    string ans = "";
    
    if (sa > sb) {
        for (int i = 0; i < (sa - sb); ++i) b = "0" + b;
        
    } 
    else if (sb > sa) {
        for (int i = 0; i < (sb - sa); ++i) a = "0" + a;
    }
    
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        int a1 = a[i] - '0';
        int b1 = b[i] - '0';
        ans += to_string((a1 + b1 + carry) % 10);
        carry = (a1 + b1 + carry) / 10;
    }
    
    if(carry)
        ans += to_string(carry);
    
    reverse(ans.begin(), ans.end());
    
    int i = 0;
    while (true){
        if(ans[i] != 0){
            break;
        }
        i++;
    }
    
    string fa = "";
    for(;i<ans.size();++i)
        fa += to_string(ans[i]-'0');
    
    return fa;
}

// Multiplication of Two number
string karastuba(string s1, string s2) {
    int ss1 = s1.size();
    int ss2 = s2.size();
    int n = max(ss1,ss2);

    if(s1 == "" or s2 == "")
        return "0";
    
    if(n < 3)
        return to_string(stoi(s1) * stoi(s2));

    n = (n/2) + (n%2);
    string a = "", b = "", c = "", d = "";

    int i=0;
    for (; i < ss1-n; ++i)
        a += to_string(s1[i] - '0');
    
    for (; i < ss1; ++i) {
        int temp = s1[i] - '0';
        b += to_string(temp);
    }
    
    int j=0;
    for (; j < ss2-n; ++j)
        c += to_string(s2[j] - '0');
    
    for (; j < ss2; ++j)
        d += to_string(s2[j] - '0');
    
    string ac = karastuba(a, c);
    string bd = karastuba(b, d);
    string ad = karastuba(a, d);
    string bc = karastuba(b, c);
    
    for (int i = 0; i < 2*n; ++i)
        ac += "0";
    
    string adbc = sumup(ad, bc);
    for (int i = 0; i < n; ++i)
        adbc += "0";
    
    string adbcbd = sumup(adbc, bd);
    string ans = sumup(ac, adbcbd);
    
    return ans;
}

int main() {
    
    int n;
    cin >> n;

    string a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        getchar();
    }

    string s;
    cin >> s;
    getchar();

    int size = s.size();

    if(size == 0 or n == 0){
        cout << "0" << endl;
        return 0;
    }

    string ans = "1";
    
    for(int i=0; i<size; ++i){
        if(s[i] != '(' and s[i] != ',' and s[i] != ')')
            ans = karastuba(ans,a[s[i]-'0']);
    }

    string fa = "";
    int i = 0;
    while(true){
        if(ans[i]!='0')
            break;
        i++;
    }

    for(;i<ans.size();i++)
        fa += ans[i];
    
    if(fa == "")
        fa = "0";

    cout << fa << endl;
    
    return 0;
}