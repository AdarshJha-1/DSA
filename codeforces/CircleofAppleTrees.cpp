#include <iostream>
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
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            arr.push_back(t);
        }

        sort(arr.begin(), arr.end());
        int currMax = 0;
        int eat = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > currMax)
            {
                eat++;
                currMax = arr[i];
            }
        }
        cout << eat << endl;
    }
    return 0;
}