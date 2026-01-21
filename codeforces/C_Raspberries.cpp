#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
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
    int ans = INT_MAX;
    int evenCount = 0;
    int temp;

    rep(i, 0, n)
    {
        cin >> temp;
        if (temp % k == 0)
        {
            ans = 0;
        }
        if (temp % 2 == 0)
        {
            evenCount++;
        }

        ans = min(ans, (k - (temp % k)));
    }

    if (k == 4)
    {
        if (evenCount == 0)
        {
            ans = min(ans, (ll)2);
        }
        else if (evenCount == 1)
        {
            ans = min(ans, (ll)1);
        }
        else if (evenCount >= 2)
        {
            ans = min(ans, (ll)0);
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