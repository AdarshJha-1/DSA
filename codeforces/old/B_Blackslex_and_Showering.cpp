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
    vector<int> arr(n, 0);

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += abs(arr[i] - arr[i + 1]);
    }

    int ans = sum;
    for (int i = 0; i < n; i++)
    {

        int curr = sum;
        if (i < n - 1)
        {
            curr -= abs(arr[i] - arr[i + 1]);
        }
        if (i > 0)
        {
            curr -= abs(arr[i] - arr[i - 1]);
        }
        if (i > 0 && i < n - 1)
        {
            curr += abs(arr[i - 1] - arr[i + 1]);
        }
        ans = min(ans, curr);
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