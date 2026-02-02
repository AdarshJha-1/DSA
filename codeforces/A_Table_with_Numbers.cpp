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
    int n, h, l;
    cin >> n >> h >> l;
    vector<int> arr(n, 0);
    rep(i, 0, n) cin >> arr[i];
    sort(arr.begin(), arr.end());

    int s = 0;
    int e = n - 1;

    int sum = 0;

    while (s < e)
    {
        int rV = arr[s];
        int cV = arr[e];

        if ((rV <= h && cV <= l) || (rV <= l && cV <= h))
        {
            s++;
            e--;
            sum++;
        }
        else
        {
            if (cV > max(h, l))
            {
                e--;
            }
            else
            {
                s++;
            }
        }
    }

    cout << sum << endl;
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