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
    if (n % 2 == 0)
    {
        int xorAns = 0;
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            xorAns ^= temp;
        }

        if (xorAns == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else
    {
        int xorAns = 0;
        int temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            xorAns ^= temp;
        }

        cout << xorAns << endl;
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