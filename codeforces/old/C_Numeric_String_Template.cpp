#include <bits/stdc++.h>
using namespace std;

#define int long long // Optional, use 64-bit everywhere
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define endl '\n' // To avoid flushing issues with '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve()
{
    // Your main logic for each test case
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int m;
    cin >> m;
    string strs[m];
    unordered_map<int, int> m;
    for (int i = 0; i < m; i++)
    {
        cin >> strs[i];
        if (strs[i].size() == n)
        {
        }
        else
        {
            no;
        }
    }
}

int32_t main()
{
    fast_io;

    int t = 1;
    // cin >> t; // Uncomment for multiple test cases
    while (t--)
    {
        solve();
    }

    return 0;
}