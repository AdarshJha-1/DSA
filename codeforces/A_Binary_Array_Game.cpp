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
    int c0 = 0, c1 = 0;

    int temp;
    rep(i, 0, n)
    {
        cin >> temp;
        if (temp == 1)
        {
            c1++;
        }
        else
        {
            c0++;
        }
    }
    if (c1 == n)
    {
        cout << "Alice" << endl;
        return;
    }
    if (c0 == n)
    {
        cout << "Bob" << endl;
        return
    }
    if (c1 >= c0)
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
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