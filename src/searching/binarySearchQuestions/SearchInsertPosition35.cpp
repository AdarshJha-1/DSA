#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    if (nums[nums.size() - 1] < target) {
        return nums.size();
    }
    int start = 0;
    int end = nums.size() - 1;
    int mid;

    while(start <= end) {
        mid = start + (end - start) / 2;
        if(nums[mid] == target) {
            return mid;
        }else if(nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return start;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 4;

    auto ans = searchInsert(nums, target);
    cout << ans << endl;
    return 0;
}
