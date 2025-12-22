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
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<int> ansV;
    ansV.push_back(b[0]);
    for (int i = 1; i < n; i++)
    {
        if (b[i] < b[i - 1])
        {
            ansV.push_back(b[i]);
        }
        ansV.push_back(b[i]);
    }
    cout << ansV.size() << endl;
    for (const auto &a : ansV)
    {
        cout << a << " ";
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