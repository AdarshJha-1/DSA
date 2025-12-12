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
    int arr[3];
    int maxE = INT_MIN, minE = INT_MAX;
    bool isSort = true;
    int lastEle = 0;
    for (int i = 0; i < 3; i++)
    {
        int temp = 0;
        cin >> temp;
        arr[i] = temp;

        if (lastEle >= temp)
        {
            isSort = false;
        }

        lastEle = temp;
        if (temp < minE)
        {
            minE = temp;
        }
        if (temp > maxE)
        {
            maxE = temp;
        }
    }

    if (isSort)
    {
        cout << "final " << arr[1] << endl;
    }
    else if (abs(minE - maxE) >= 10)
    {
        cout << "check again" << endl;
    }
    else
    {
        cout << "final " << arr[0] + arr[1] + arr[2] - minE - maxE << endl;
    }
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