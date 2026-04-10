#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    long long x = 1000000000000000000; // 10^18
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int val;
            cin >> val;
            arr[i] = val;
        }

        for (long long i = 2; i < x; i++)
        {
            if (i % arr[0] == 1)
            {
                cout << i;
                break;
            }
        }
        cout << endl;
    }
    return 0;
}