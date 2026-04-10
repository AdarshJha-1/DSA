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
    int negSum = 0;
    int posSum = 0;
    // int i = 0;
    // while (i < n - 1)
    // {
    //     int temp;
    //     cin >> temp;
    //     if (temp < 0)
    //     {
    //         negSum += temp;
    //     }
    //     else
    //     {
    //         posSum += temp;
    //     }
    //     i++;
    // }

    // negSum *= -1;
    // cout << negSum - posSum << endl;

    int sum = 0;
    while (n > 1 && n--)
    {
        int temp;
        cin >> temp;
        sum += temp;
    }
    cout << sum * -1 << endl;
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