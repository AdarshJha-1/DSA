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
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];

    int l = 0;
    while (l < n)
    {
        if (p[l] != n - l)
            break;
        l++;
    }

    int r = l + 1;
    while (r < n && p[r] != n - l)
    {
        r++;
    }

    if (l == n)
    {
        for (const auto &n : p)
        {
            cout << n << " ";
        }
        cout << endl;
        return;
    }
    reverse(p.begin() + l, p.begin() + r + 1);
    for (const auto &n : p)
    {
        cout << n << " ";
    }
    cout << endl;
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