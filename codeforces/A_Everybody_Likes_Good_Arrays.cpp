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
    int arr[n];
    rep(i, 0, n) cin >> arr[i];

    int ans = 0;
    int count = 0;
    rep(i, 0, n - 1)
    {
        int p1 = arr[i] % 2;
        int p2 = arr[i + 1] % 2;
        if (p1 != p2)
        {
            ans += count;
            count = 0;
        }
        else
        {
            count++;
        }
    }

    ans += count;

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