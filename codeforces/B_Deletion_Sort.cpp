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
    vector<int> arr(n);

    bool isSorted = true;
    rep(i, 0, n)
    {
        cin >> arr[i];
        if (i > 0 && arr[i] < arr[i - 1])
        {
            isSorted = false;
        }
    }
    if (isSorted)
    {
        cout << arr.size() << endl;
    }
    else
    {
        cout << 1 << endl;
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