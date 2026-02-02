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
    int n, s, x;
    cin >> n >> s >> x;
    int totalSum = 0;
    int temp;
    rep(i, 0, n)
    {
        cin >> temp;
        totalSum += temp;
    }

    if (totalSum == s)
    {
        yes;
        return;
    }

    if (totalSum > s)
    {
        no;
        return;
    }

    int diff = s - totalSum;
    if (diff % x == 0)
    {
        yes;
        return;
    }
    else
    {
        no;
        return;
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