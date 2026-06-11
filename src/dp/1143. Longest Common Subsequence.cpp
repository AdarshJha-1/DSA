class Solution
{
public:
    vector<vector<int>> dp;

    int sol(string &text1, string &text2, int i, int j)
    {
        if (i >= text1.size() || j >= text2.size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (text1[i] == text2[j])
        {
            return dp[i][j] = 1 + sol(text1, text2, i + 1, j + 1);
        }
        else
        {
            int left = sol(text1, text2, i + 1, j);
            int right = sol(text1, text2, i, j + 1);

            return dp[i][j] = max(left, right);
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        dp.resize(text1.size() + 1, vector<int>(text2.size() + 1, -1));
        return sol(text1, text2, 0, 0);
    }
};

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};