class Solution
{
public:
    vector<int> dp;

    int sol(vector<int> &nums, int idx)
    {
        if (idx >= nums.size())
        {
            return 0;
        }

        if (dp[idx] != -1)
        {
            return dp[idx];
        }

        int rob = nums[idx] + sol(nums, idx + 2);
        int skip = sol(nums, idx + 1);

        return dp[idx] = max(rob, skip);
    }

    int rob(vector<int> &nums)
    {
        dp.resize(nums.size(), -1);

        return sol(nums, 0);
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++)
        {
            int rob = nums[i - 1] + dp[i - 2];
            int skip = dp[i - 1];

            dp[i] = max(rob, skip);
        }

        return dp[n];
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int a = 0;
        int b = nums[0];

        int n = nums.size();
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                a = max(a + nums[i - 1], b);
            }
            else
            {
                b = max(b + nums[i - 1], a);
            }
        }

        return max(a, b);
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int pp = 0;
        int p = nums[0];

        for (int i = 2; i <= nums.size(); i++)
        {
            int totalRob = max(nums[i - 1] + pp, p);
            pp = p;
            p = totalRob;
        }
        return p;
    }
};