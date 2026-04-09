class Solution
{
public:
    vector<vector<long long>> dp;

    long long sol(vector<int> &nums, int i, bool flag)
    {
        if (i >= nums.size())
        {
            return 0;
        }

        if (dp[i][flag] != -1)
        {
            return dp[i][flag];
        }

        long long val = nums[i];
        if (!flag)
        {
            val = -val;
        }
        long long take = sol(nums, i + 1, !flag) + val;
        long long skip = sol(nums, i + 1, flag);

        return dp[i][flag] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int> &nums)
    {
        dp.resize(nums.size() + 1, vector<long long>(2, -1));
        return sol(nums, 0, true);
    }
};