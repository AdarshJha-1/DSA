class Solution
{
public:
    int absDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int minSum = 0;
        int maxSum = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (k--)
        {
            minSum += nums[i++];
            maxSum += nums[j--];
        }
        return abs(minSum - maxSum);
    }
};