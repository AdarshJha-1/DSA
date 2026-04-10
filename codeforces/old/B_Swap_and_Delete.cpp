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

    int c0 = 0;
    int c1 = 0;
    for (const auto &c : s)
    {
        if (c == '0')
            c0++;
        if (c == '1')
            c1++;
    }

    if (c1 == s.size() || c0 == s.size())
    {
        cout << s.size() << endl;
    }
    else if (c1 == c0)
    {
        cout << 0 << endl;
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1' && c0 > 0)
            {
                c0--;
            }
            else if (s[i] == '0' && c1 > 0)
            {
                c1--;
            }
            else if (c1 == 0 || c0 == 0)
            {
                cout << c1 + c0 << endl;
                return;
            }
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