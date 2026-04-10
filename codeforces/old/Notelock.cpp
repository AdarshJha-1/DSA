#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        int ans = 0;
        int lastProtected = -k;

        for (int i = 0; i < n; i++)
        {
            if (str[i] == '1')
            {
                bool canChange = true;
                for (int j = max(0, i - (k - 1)); j < i; j++)
                {
                    if (str[j] == '1')
                    {
                        canChange = false;
                        break;
                    }
                }

                if (canChange && (i - lastProtected) >= k)
                {
                    ans++;
                    lastProtected = i;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
