class Solution
{
public:
    int dp[101];

    int sol(vector<int> &nums, int idx, int n)
    {
        if (idx >= n)
        {
            return 0;
        }

        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        int rob = nums[idx] + sol(nums, idx + 2, n);
        int skip = sol(nums, idx + 1, n);

        return dp[idx] = max(rob, skip);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        memset(dp, -1, sizeof(dp));
        int ans1 = sol(nums, 0, n - 1);

        memset(dp, -1, sizeof(dp));
        int ans2 = sol(nums, 1, n);
        return max(ans1, ans2);
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }

        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);

        dp1[0] = 0;
        dp1[1] = nums[0];
        for (int i = 2; i < n; i++)
        {
            dp1[i] = max(dp1[i - 1], (nums[i - 1] + dp1[i - 2]));
        }

        dp2[0] = 0;
        dp2[1] = nums[1];
        for (int i = 2; i < n; i++)
        {
            dp2[i] = max(dp2[i - 1], (nums[i] + dp2[i - 2]));
        }

        return max(dp1[n - 1], dp2[n - 1]);
    }
};