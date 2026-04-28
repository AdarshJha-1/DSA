class Solution
{
public:
    vector<vector<int>> dp;

    int sol(vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp, int r, int c, int m, int n)
    {
        if (r >= m || c >= n)
        {
            return 0;
        }

        if (obstacleGrid[r][c] == 1)
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

        int down = sol(obstacleGrid, dp, r + 1, c, m, n);
        int right = sol(obstacleGrid, dp, r, c + 1, m, n);

        return dp[r][c] = down + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }
        dp.resize(m, vector<int>(n, -1));

        return sol(obstacleGrid, dp, 0, 0, m, n);
    }
};

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1)
        {
            return 0;
        }
        vector<vector<long>> dp(m, vector<long>(n, 0));

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                }
                else if (i == m - 1 && j == n - 1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    long down = (i + 1 >= m) ? 0 : dp[i + 1][j];
                    long right = (j + 1 >= n) ? 0 : dp[i][j + 1];

                    dp[i][j] = down + right;
                }
            }
        }
        return dp[0][0];
    }
};