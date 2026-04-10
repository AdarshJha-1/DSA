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
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;

    string x0 = x;
    string x1 = x0 + x0;
    string x2 = x1 + x1;
    string x3 = x2 + x2;
    string x4 = x3 + x3;
    string x5 = x4 + x4;

    int ans = -1;
    if (x0.find(s) != x0.npos)
    {
        ans = 0;
    }
    else if (x1.find(s) != x1.npos)
    {
        ans = 1;
    }
    else if (x2.find(s) != x2.npos)
    {
        ans = 2;
    }
    else if (x3.find(s) != x3.npos)
    {
        ans = 3;
    }
    else if (x4.find(s) != x4.npos)
    {
        ans = 4;
    }
    else if (x5.find(s) != x5.npos)
    {
        ans = 5;
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