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
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    cin >> a >> b >> c >> m;

    int A = m / a;
    int B = m / b;
    int C = m / c;

    int AB = m / lcm(a, b);
    int AC = m / lcm(a, c);
    int BC = m / lcm(b, c);

    int ABC = m / lcm(a, lcm(b, c));

    int AB_only = AB - ABC;
    int AC_only = AC - ABC;
    int BC_only = BC - ABC;

    int A_only = A - AB_only - AC_only - ABC;
    int B_only = B - AB_only - BC_only - ABC;
    int C_only = C - AC_only - BC_only - ABC;

    int alice = 6 * A_only + 3 * AB_only + 3 * AC_only + 2 * ABC;
    int bob = 6 * B_only + 3 * AB_only + 3 * BC_only + 2 * ABC;
    int carol = 6 * C_only + 3 * AC_only + 3 * BC_only + 2 * ABC;

    cout << alice << " " << bob << " " << carol << "\n";
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