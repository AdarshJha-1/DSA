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
    int n, q;
    cin >> n >> q;
    n += 1;
    vector<int> a(n, 0), b(n, 0);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) cin >> b[i];

    vector<int> suf(n, 0);
    suf[n - 1] = max(a[n - 1], b[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        int temp = max(a[i], b[i]);
        suf[i] = max(temp, suf[i + 1]);
    }

    vector<int> prefix(n, 0);
    prefix[1] = suf[1];
    for (int i = 2; i < n; i++)
    {
        prefix[i] = suf[i] + prefix[i - 1];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << " ";
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