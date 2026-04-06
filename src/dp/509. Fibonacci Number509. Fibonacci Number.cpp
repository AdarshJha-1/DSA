class Solution
{
public:
    vector<int> dp;

    int sol(int n)
    {
        if (n <= 1)
        {
            return dp[n] = n;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = sol(n - 1) + sol(n - 2);
    }

    int fib(int n)
    {
        dp.resize(n + 1, -1);
        return sol(n);
    }
};
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        int f = 0;
        int s = 1;
        for (int i = 2; i <= n; i++)
        {
            int sum = f + s;
            f = s;
            s = sum;
        }
        return s;
    }
};