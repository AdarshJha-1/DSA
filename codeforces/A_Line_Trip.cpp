#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr;
        arr.push_back(0);
        for (int i = 0; i < n; i++)
        {
            int v;
            cin >> v;
            arr.push_back(v);
        }

        arr.push_back(x);

        vector<int> dist;
        for (int i = 1; i < arr.size() - 1; i++)
        {
            dist.push_back(arr[i] - arr[i - 1]);
        }
        dist.push_back(2 * (arr[arr.size() - 1] - arr[arr.size() - 2]));

        sort(dist.begin(), dist.end());
        cout << dist[dist.size() - 1] << "\n";
    }
    return 0;
}