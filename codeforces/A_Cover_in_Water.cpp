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
        string s;
        cin >> s;

        bool isThreeCellEmpty = false;
        int emptyCells = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '.' && s[i - 1] == '.' && s[i + 1] == '.')
                isThreeCellEmpty = true;
        }

        if (isThreeCellEmpty)
        {
            cout << 2 << "\n";
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '.')
                    emptyCells++;
            }
            cout << emptyCells << "\n";
        }
    }
    return 0;
}