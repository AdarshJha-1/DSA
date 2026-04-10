#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, a, n) for (int i = (a); i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (n == a && n == b)
    {
        yes;
        return;
    }
    int sum = a + b + 2;
    if (sum <= n)
    {
        yes;
    }
    else
    {
        no;
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