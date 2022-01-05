#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;

void permute(vector<int> &a, int idx)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }

    for (int i = 0; i < a.size(); i++)
    {
        swap(a[i], a[idx]);
        permute(a, idx + 1);
        swap(a[i], a[idx]);
    }
}

int main()
{
    freopen("input_file.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    permute(a, 0);
    // sort(a.begin(), a.end());
    // do
    // {
    //     ans.push_back(a);
    // } while (next_permutation(a.begin(), a.end()));

    for (auto v : ans)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
