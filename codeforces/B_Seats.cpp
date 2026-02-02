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
    string str;
    cin >> str;

    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    if (str[0] == '0' && str[1] == '0')
    {
        str[1] == '1';
    }
    if (str[n - 1] == '0' && str[n - 2] == '0')
    {
        str[n - 2] == '1';
    }

    int ans = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
        {
            ans++;
            count = 0;
        }
        if (str[i] == '0')
        {
            count++;
        }
        if (count >= 3)
        {
            ans++;
        }
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