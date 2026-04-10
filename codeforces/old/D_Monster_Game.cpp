#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
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
    n += 1;
    vi a(n, 0), b(n, 0);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];
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