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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a == c && b == d)
    {
        cout << 0 << endl;
        return;
    }
    if (d < b)
    {
        cout << -1 << endl;
        return;
    }
    int x, y;
    x = (d - b) + a;
    y = (d - b) + b;
    if (x < c)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << (x - c) + (d - b) << endl;
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