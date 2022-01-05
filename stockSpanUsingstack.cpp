#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define loop(a,b,inc) for(int i=a;i<=b;i+=inc)
#define oset tree<int, null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
#define ll long long int
#define vi vector<int>
#define li list<int>
#define pii pair<int,int>
#define umii unordered_map<int,int>
#define mii map<int,int>
#define qi queue<int>
using namespace __gnu_pbds;

vector<int> stock_span(vi prices,int n)
{
    vi ans;
    stack<pair<int,int>> s; // pair of stock value and day(how many days)
    for(int i=0; i<n; i++)
    {
        int days=1;
        while(!s.empty() and prices[i] >= s.top().first ){
            days+=(s.top().second);
            s.pop();
        }
        s.push({prices[i],days});
        ans.push_back(days);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vi a(n);
    loop(0,n-1,1)
        cin >> a[i];
    vector<int> ans = stock_span(a,n);
    for(auto x:ans)
        cout<<x<<" ";
    return 0;
}