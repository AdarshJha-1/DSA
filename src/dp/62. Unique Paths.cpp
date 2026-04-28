class Solution
{
public:
    vector<vector<int>> dp;
    int sol(int r, int c, int m, int n)
    {
        if (r >= m || c >= n)
        {
            return 0;
        }
        if (r == m - 1 && c == n - 1)
        {
            return 1;
        }
        if (dp[r][c] != -1)
        {
            return dp[r][c];
        }

        int down = sol(r + 1, c, m, n);
        int right = sol(r, c + 1, m, n);

        return dp[r][c] = down + right;
    }

    int uniquePaths(int m, int n)
    {
        dp.resize(m, vector<int>(n, -1));
        return sol(0, 0, m, n);
    }
};

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 || j == n - 1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }

        return dp[0][0];
    }
};