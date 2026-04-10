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
#define no cout << "NO\n")

void solve()
{
    int n;
    cin >> n;
    int ans = 0;

    for (int i = 1; i < 10; i++)
    {
        if (n >= i)
            ans++;
    }
    for (int i = 10; i < 100; i += 10)
    {
        if (n >= i)
            ans++;
    }
    for (int i = 100; i < 1000; i += 100)
    {
        if (n >= i)
            ans++;
    }
    for (int i = 1000; i < 10000; i += 1000)
    {
        if (n >= i)
            ans++;
    }
    for (int i = 10000; i < 100000; i += 10000)
    {
        if (n >= i)
            ans++;
    }
    for (int i = 100000; i < 1000000; i += 100000)
    {
        if (n >= i)
            ans++;
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