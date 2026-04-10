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
    rep(i, 0, n)
    {
        cin >> arr[i];
    }
    int maxEle = *max_element(arr.begin(), arr.end());
    int count = 0;
    for (const auto &e : arr)
    {
        if (e == maxEle)
        {
            count++;
        }
    }
    cout << count << endl;
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