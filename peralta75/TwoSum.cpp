class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
            else if (nums[i] + nums[j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }

        return {-1, -1};
    }
};