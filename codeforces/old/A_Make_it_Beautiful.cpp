#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, a, n) for (int i = (a); i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    rep(i, 0, n) cin >> arr[i];

    sort(arr.begin(), arr.end());
    if (arr[0] == arr[arr.size() - 1])
    {
        no;
    }
    else
    {
        yes;
        cout << arr[arr.size() - 1] << " ";
        for (int i = 0; i < n - 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
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