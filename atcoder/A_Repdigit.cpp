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
    int N;
    cin >> N;
    int digit = N % 10;
    N /= 10;
    while (N)
    {
        if (N % 10 != digit)
        {
            cout << "No" << endl;
            return;
        }
        N /= 10;
    }

    cout << "Yes" << endl;
}

int32_t main()
{
    fast_io;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}