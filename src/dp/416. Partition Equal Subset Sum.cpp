class Solution 
{
public:

    vector<vector<int>> dp;
    bool sol(vector<int>& nums, int i, int n, int target, int currSum)
    {
        if(currSum == target)
        {
            return true;
        }

        if(i == n || currSum > target)
        {
            return false;
        }

        if(dp[i][currSum] != -1)
        {
            return dp[i][currSum];
        }

        bool take = sol(nums, i + 1, n, target, currSum + nums[i]);
        bool skip = sol(nums, i + 1, n, target, currSum);

        return dp[i][currSum] = take || skip;
    }

    bool canPartition(vector<int>& nums) 
    {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum % 2)
        {
            return false;
        }

        dp.resize(n, vector<int>(totalSum + 1, -1));
        return sol(nums, 0, n, totalSum / 2, 0);
    }
};
