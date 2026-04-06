class Solution
{
public:
    vector<int> dp;

    int sol(int n)
    {
        if (dp[n] != -1)
        {
            return dp[n];
        }
        if (n <= 1)
        {
            return 1;
        }
        return dp[n] = sol(n - 1) + sol(n - 2);
    }

    int climbStairs(int n)
    {
        dp.resize(n + 1, -1);
        return sol(n);
    }
};