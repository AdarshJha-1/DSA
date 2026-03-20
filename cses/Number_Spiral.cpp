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
    int r, c;
    cin >> r >> c;
    if (r >= c)
    {
        if (r % 2 == 0)
        {
        }
        cout << (r * r) - (c - 1) << endl;
    }
    else
    {
        if (c % 2 == 0)
        {
        }
        else
        {
            cout << (c * c) - (r - 1) << endl;
        }
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