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
    string s;
    cin >> s;
    int ans = 0;
    rep(i, 0, s.size())
    {
        char c = s[i];
        int val = c - '0';
        int inVal = 9 - val;

        if (i == 0 && inVal == 0)
        {
            ans = ans * 10 + val;
        }
        else if (inVal < val)
        {
            ans = ans * 10 + inVal;
        }
        else
        {
            ans = ans * 10 + val;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    fast_io;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}