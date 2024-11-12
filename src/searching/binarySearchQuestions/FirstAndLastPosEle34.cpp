#include <iostream>
#include <vector>

using namespace std;
int firstOcc(vector<int> &nums, int target, int n)
{
    int first = -1;
    int start = 0;
    int end = n - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            first = mid;
            end = mid - 1;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return first;
}

int lastOcc(vector<int> &nums, int target, int n)
{
    int last = -1;
    int start = 0;
    int end = n - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] == target)
        {
            last = mid;
            start = mid + 1;
        }
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return last;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans;
    int n = nums.size();
    int first, last;
    first = firstOcc(nums, target, n);
    last = lastOcc(nums, target, n);
    ans.push_back(first);
    ans.push_back(last);
    return ans;
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    auto ans = searchRange(nums, target);
    cout << ans[0] << endl
         << ans[1];
    return 0;
}
