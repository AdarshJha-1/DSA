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
    int n, k;
    cin >> n >> k;

    int temp = n;
    int cost = 0;
    while (temp > 1)
    {
        cost++;
        int x = temp / 2;
        if (x == k)
        {
            cout << cost << endl;
            return;
        }
        int y = abs(x - temp);
        if (y == k)
        {
            cout << cost << endl;
            return;
        }
        temp = y;
    }

    cout << -1 << endl;
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