#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            arr[i] = val;
        }

        bool hasOdd = false, hasEven = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 1)
                hasOdd = true;
            if (arr[i] % 2 == 0)
                hasEven = true;
        }
        if (hasOdd && hasEven)
        {
            sort(arr.begin(), arr.end());
        }

        for (auto &v : arr)
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}