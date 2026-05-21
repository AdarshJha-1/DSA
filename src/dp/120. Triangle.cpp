class Solution 
{
public:

    vector<vector<int>> dp;

    int sol(vector<vector<int>>& triangle, int n, int r, int i)
    {
        if(r == n - 1)
        {
            return triangle[r][i];
        }

        if(dp[r][i] != INT_MAX)
        {
            return dp[r][i];
        }
        int first = sol(triangle, n, r + 1, i) + triangle[r][i];
        int second = sol(triangle, n, r + 1, i + 1) + triangle[r][i];

        return dp[r][i] = min(first, second);
    }

    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        dp.resize(n, vector<int>(n, INT_MAX));
        return sol(triangle, n, 0, 0);
    }
};
