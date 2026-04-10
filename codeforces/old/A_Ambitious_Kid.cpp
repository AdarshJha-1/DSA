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
    int smallestVal = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        smallestVal = min(smallestVal, abs(temp));
    }

    cout << smallestVal << endl;
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