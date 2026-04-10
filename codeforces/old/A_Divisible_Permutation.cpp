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
    vector<int> ans(n + 1, 0);
    if (n % 2 == 0)
    {
        ans[1] = n;
        int acu = n - 1;
        int i = 2;

        while (i < n + 1)
        {
            if (i % 2 == 0)
            {
                ans[i] = ans[i - 1] - acu;
            }
            else
            {
                ans[i] = ans[i - 1] + acu;
            }
            acu--;
            i++;
        }
    }
    else
    {

        ans[1] = 1;
        int acu = n - 1;
        int i = 2;

        while (i < n + 1)
        {
            if (i % 2 == 0)
            {
                ans[i] = ans[i - 1] + acu;
            }
            else
            {
                ans[i] = ans[i - 1] - acu;
            }
            acu--;
            i++;
        }
    }

    for (int i = n; i >= 1; i--)
    {
        cout << ans[i] << " ";
    }
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