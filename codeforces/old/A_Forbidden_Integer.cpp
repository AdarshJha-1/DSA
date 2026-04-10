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
    int n, k, x;
    cin >> n >> k >> x;

    if (x != 1)
    {
        cout << "YES" << endl;
        cout << n << endl;
        while (n--)
        {
            cout << 1 << " ";
        }
        cout << endl;
    }
    else
    {
        if (k == 1 && x == 1)
        {
            cout << "NO" << endl;
            return;
        }
        if (k == 2 && n % 2 == 0)
        {
            cout << "YES" << endl;
            int temp = n / 2;
            cout << temp << endl;
            while (temp--)
            {
                cout << 2 << " ";
            }
            cout << endl;
            return;
        }
        else if (k >= 3)
        {
            if (n % 2 == 0)
            {
                cout << "YES" << endl;
                int temp = n / 2;
                cout << temp << endl;
                while (temp--)
                {
                    cout << 2 << " ";
                }
                cout << endl;
                return;
            }
            else
            {
                int ans = 1;
                n -= 3;
                ans += n / 2;
                cout << "YES" << endl;
                cout << ans << endl;
                while (ans-- > 1)
                {
                    cout << 2 << " ";
                }
                cout << 3 << endl;
                return;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
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