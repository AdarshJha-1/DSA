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

    vector<int> arr(n, 0);
    int c1 = 0, c2 = 0;
    int temp;
    rep(i, 0, n)
    {
        cin >> temp;
        arr[i] = temp;
        if (temp == 1)
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    if (c2 == 0)
    {
        cout << 1 << endl;
    }
    else if (c2 % 2 == 0)
    {
        int j = c2 / 2;
        int i = 0;
        while (j > 0)
        {
            if (arr[i] == 2)
            {
                j--;
            }
            i++;
        }
        cout << i << endl;
    }
    else
    {
        cout << -1 << endl;
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