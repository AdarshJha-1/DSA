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
    int temp;
    int pos = 0;
    int neg = 0;
    rep(i, 0, n)
    {
        cin >> temp;
        if (temp < 0)
        {
            neg++;
        }
        else
        {
            pos++;
        }
    }

    if (pos >= neg)
    {
        if (neg % 2 == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    else
    {
        int ans = 0;
        while (neg > pos)
        {
            pos++;
            neg--;
            ans++;
        }

        if (neg % 2 == 0)
        {
            cout << ans << endl;
        }
        else
        {
            cout << ans + 1 << endl;
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