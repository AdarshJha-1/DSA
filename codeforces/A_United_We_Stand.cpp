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
    int n;
    cin >> n;
    vector<int> a(n, 0);
    int smallestVal = INT_MAX;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        smallestVal = min(smallestVal, temp);
        a[i] = temp;
    }

    vector<int> b;
    vector<int> c;

    for (const auto &val : a)
    {
        if (val == smallestVal)
        {
            b.push_back(val);
        }
        else
        {
            c.push_back(val);
        }
    }

    if (b.size() == 0 || c.size() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << b.size() << " " << c.size() << endl;
        for (const auto &val : b)
        {
            cout << val << " ";
        }
        cout << endl;
        for (const auto &val : c)
        {
            cout << val << " ";
        }
        cout << endl;
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