#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define yes cout << "YES\n"
#define no cout << "NO\n"

void solve()
{
    int n, k;
    cin >> n >> k;
    bool hasK = false;
    while (n--)
    {
        int temp;
        cin >> temp;
        if (temp == k)
        {
            hasK = true;
        }
    }
    hasK ? (cout << "YES" << endl) : (cout << "NO" << endl);
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