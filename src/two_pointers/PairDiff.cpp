#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pairDiff(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());

    int start = 0;
    int end = 1;
    while (end < arr.size())
    {
        if (arr[end] - arr[start] == target)
        {
            return 1;
        } else if (arr[end] - arr[start] < target) {
            end++;
        } else {
            start++;
        }
    }
    return 0;
}

int main()
{

    vector<int> arr = {5, 10, 3, 2, 50, 80};
    int target = 78;
    int ans = pairDiff(arr, target);
    cout << ans << endl;
    return 0;
}  