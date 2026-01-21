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
    int n, p;
    cin >> n >> p;

    vector<int> a(n);
    vector<pair<int, int>> arr(n);
    rep(i, 0, n) cin >> a[i];
    int temp;
    rep(i, 0, n)
    {
        cin >> temp;
        arr[i] = {temp, a[i]};
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    int remain = n;
    int i = 0;
    while (i < arr.size() && remain)
    {
        auto ele = arr[i];
        if (ele.first < p)
        {
            ans += p;
            remain--;
            if (ele.second > remain)
            {
                ans += ele.first * remain;
                remain = 0;
            }
            else
            {
                ans += ele.first * ele.second;
                remain -= ele.second;
            }
        }
        else
        {
            break;
        }
        i++;
    }

    if (remain > 0)
    {
        ans += p * remain;
    }
    cout << ans << endl;
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