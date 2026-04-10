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
    int x, k;
    cin >> x >> k;

    if (x % k == 0)
    {
        cout << 2 << endl;
        cout << 1 << " " << x - 1 << endl;
    }
    else
    {
        cout << 1 << endl;
        cout << x << endl;
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