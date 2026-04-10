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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> arr(n, 0);
    rep(i, 0, n)
    {
        cin >> arr[i];
    }

    int totalTransfers = 0;
    for (auto a : arr)
        totalTransfers += a / x;

    int ans = 0;

    for (auto a : arr)
    {
        int cur =
            a + (totalTransfers - a / x) * y;
        ans = max(ans, cur);
    }

    cout << ans << endl;
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