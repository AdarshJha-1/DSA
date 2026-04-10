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
    int n = s.size();
    vector<int> ans;
    int count = 0;
    rep(i, 0, n)
    {
        char c = s[i];
        int val = c - '0';
        int len = n - i - 1;
        if (val != 0)
        {
            switch (len)
            {
            case 0:
                ans.push_back(val);
                break;
            case 1:
                ans.push_back(val * 10);
                break;

            case 2:
                ans.push_back(val * 100);
                break;

            case 3:
                ans.push_back(val * 1000);
                break;

            case 4:
                ans.push_back(val * 10000);
                break;
            default:
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (const auto &a : ans)
        cout << a << " ";

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