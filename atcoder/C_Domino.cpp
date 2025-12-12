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
    int N;
    cin >> N;
    vector<int> arr(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    int i = 1;
    int ans = 0;
    while (i < N + 1)
    {
        if (arr[i] == 1)
        {
            ans++;
            break;
        }
        else if (i > N + 1)
        {
            ans += N - i;
        }
        else
        {
            int temp = i + (arr[i] - 1);
            ans += temp;
            i = temp;
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    fast_io;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}