#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int first = 1;
    int second = 1;
    if (nums.size(f) >= 2) {
        second = 2;
    }
    while (second < nums.size())
    {
        if (nums[first] == nums[second])
        {
            second++;
        }
        else
        {
            if (nums[first - 1] == nums[second])
            {
                second++;
            }
            nums[first] = nums[second];
            first++;
            second++;
        }
    }
    return first;
}

int main()
{
    // vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> nums = {1, 2};
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    int ans = removeDuplicates(nums);
    cout << endl;
    for (int i = 0; i < ans; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}