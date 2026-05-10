class Solution {
public:
    // TLE
    int ans = 0;

    void sol(vector<int>& nums, int i, int currLen, int lastEl, int n)
    {
        if(i == n)
        {
            ans = max(ans, currLen);
            return;
        }
        sol(nums, i + 1, currLen, lastEl, n);
        if(nums[i] > lastEl)
        {
            currLen++;
            lastEl = nums[i];
            sol(nums, i + 1, currLen, lastEl, n);
        }
    }

    int lengthOfLIS(vector<int>& nums) 
    {
        sol(nums, 0, 0, INT_MIN, nums.size());
        return ans;
    }
};

class Solution {
public:

    vector<vector<int>> dp;

    int sol(vector<int>& nums, int i, int lastIdx, int n)
    {
        if(i == n)
        {
            return 0;
        }
        if(lastIdx != -1 && dp[i][lastIdx] != -1)
        {
            return dp[i][lastIdx];
        }
        int skip = sol(nums, i + 1, lastIdx, n);
        int take = 0;
        if(lastIdx == -1 || nums[i] > nums[lastIdx])
        {
            take = 1 + sol(nums, i + 1, i, n);
        }
        if(lastIdx != -1)
        {
            return dp[i][lastIdx] = max(skip, take);
        }
        return max(skip, take);
    }

    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        dp.resize(2501, vector<int>(2501, -1));
        return sol(nums, 0, -1, n);
    }
};

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
