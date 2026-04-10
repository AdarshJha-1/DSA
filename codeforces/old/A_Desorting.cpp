#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    int lastVal = INT_MIN;
    bool isNotSorted = false;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp < lastVal)
        {
            isNotSorted = true;
        }
        lastVal = temp;
        arr[i] = temp;
    }

    if (isNotSorted)
    {
        cout << 0 << endl;
    }
    else
    {
        int minDiff = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            // cout << arr[i] - arr[i + 1] << endl;
            minDiff = min(minDiff, (arr[i + 1] - arr[i]));
        }
        // cout << minDiff << endl;
        cout << (minDiff / 2) + 1 << endl;
    }
}

int32_t main()
{
    fast_io;

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}