#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        map<long long, long long> m;
        for (int i = 0; i < n; i++)
            m[arr[i]]++;

        if (m.size() >= 3)
        {
            cout << "No" << "\n";
        }
        else
        {
            long long f1 = m.begin()->second;
            long long f2 = m.rbegin()->second;

            if (f1 == f2)
            {
                cout << "Yes" << "\n";
            }
            else if (n % 2 == 1 && abs(f1 - f2) == 1)
            {
                cout << "Yes" << "\n";
            }
            else
            {
                cout << "No" << "\n";
            }
        }
    }

    return 0;
}