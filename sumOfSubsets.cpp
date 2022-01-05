#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define loop(a, b, inc) for (int i = a; i <= b; i += inc)
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
#define ll long long int
#define vi vector<int>
#define li list<int>
#define pii pair<int, int>
#define umii unordered_map<int, int>
#define mii map<int, int>
#define qi queue<int>
using namespace __gnu_pbds;

void sumOfSubsets(int a[], int m, int n)
{
    for (int i = 0; i < (1 << n); ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                sum = sum + a[j];
            }
        }
        if (sum == m)
        {
            cout << i << " found\n";
            for (int k = 0; k < n; k++)
            {
                if ((i & (1 << k)) != 0)
                {
                    cout << a[k] << " ";
                }
            }
            printf("\n");
        }
    }
}

void sumOf(int wt[], int total, int sz, vector<int> &ans, int idx, int currWt, int totalWt)
{
    if (currWt + wt[idx] == total)
    {
        ans[idx] = 1;
        currWt += wt[idx];
        totalWt -= wt[idx];
        return;
    }
    if (currWt + wt[idx] > total)
    {
        ans[idx] = 0;
        totalWt -= wt[idx];
        return;
    }
    if (totalWt + currWt < total)
    {
        return;
    }
    ans[idx] = 1;
    currWt += wt[idx];
    totalWt -= wt[idx];
    sumOf(wt, total, sz, ans, idx + 1, currWt, totalWt);
}

int main()
{
    // freopen("input_file.txt", "r", stdin);
    int arr[] = {5, 7, 10, 12, 15};
    int currWt = 0;
    int totalWt = 0;
    for (int i = 0; i < 7; i++)
        totalWt += arr[i];
    int m = 25;
    // sumOfSubsets(arr, m, 7);
    vector<int> ans(6, false);
    sumOf(arr, m, 6, ans, 0, currWt, totalWt);
    for (int i = 0; i < 6; i++)
    {
        if (ans[i] == 1)
            cout << arr[i] << " ";
    }
    return 0;
}