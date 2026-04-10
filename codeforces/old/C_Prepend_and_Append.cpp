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
    string s;
    cin >> s;
    int i = 0;
    int j = s.size() - 1;
    while (s[i] != s[j])
    {
        // cout << s[i] << " " << s[j] << endl;
        i++;
        j--;
    }
    if (i > j)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << (j - i) + 1 << endl;
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