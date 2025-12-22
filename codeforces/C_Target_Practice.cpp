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
    vector<vector<int>> target(10, vector<int>(10, 0));
    int point = 1;
    int row = 0;
    while (row < 5)
    {
        for (int i = row; i < 10 - row; i++)
            target[row][i] = point;
        for (int i = row; i < 10 - row; i++)
            target[i][row] = point;
        for (int i = row; i < 10 - row; i++)
            target[10 - 1 - row][i] = point;
        for (int i = row; i < 10 - row; i++)
            target[i][10 - 1 - row] = point;

        row++;
        point++;
    }

    while (row < 10)
    {
        for (int i = row; i < 10 - row; i++)
            target[row][i] = point;
        for (int i = row; i < 10 - row; i++)
            target[i][row] = point;
        for (int i = row; i < 10 - row; i++)
            target[10 - 1 - row][i] = point;
        for (int i = row; i < 10 - row; i++)
            target[i][10 - 1 - row] = point;

        row++;
        point--;
    }

    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        char scored = ' ';
        for (int j = 0; j < 10; j++)
        {
            cin >> scored;
            if (scored == 'X')
            {
                ans += target[i][j];
            }
        }
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