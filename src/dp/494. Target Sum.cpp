class Solution 
{
public:

    vector<vector<int>> dp;
    int offset = 0;

    int sol(vector<int>& nums, int target, int curr, int i, int n)
    {   
        if(i == n)
        {
            if(curr == target)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][offset - curr] != -1)
        {
            return dp[i][offset - curr];
        }

        int plus = 0, minus = 0;
        plus += sol(nums, target, curr + nums[i], i + 1, n);
        minus += sol(nums, target, curr - nums[i], i + 1, n);

        return dp[i][offset - curr] = plus + minus;
    } 

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        offset = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        dp.resize(n, vector<int>(2 * offset + 1, -1));
        return sol(nums, target, 0, 0, n);
    }
};
