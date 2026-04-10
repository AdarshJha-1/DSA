#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0, k = 0;
        cin >> n >> k;

        int arr[n];
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        if (k > 1)
        {
            cout << "YES\n";
        }
        else
        {
            bool isSorted = true;
            for (int i = 1; i < n; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    isSorted = false;
                    break;
                }
            }
            isSorted ? cout << "YES\n" : cout << "NO\n";
        }
    }
    return 0;
}