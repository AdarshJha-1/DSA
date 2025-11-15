#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int ans = 0;
        int mm = max(x, y);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] + arr[j] >= mm && (arr[i] + arr[j]) % x == 0 && (arr[i] - arr[j]) % y == 0)
                {
                    // cout << arr[i] << " " << arr[j] << endl;
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
