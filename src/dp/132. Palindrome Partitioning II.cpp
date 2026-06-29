class Solution
{
public:
    int sol(string &s, int i, vector<vector<bool>> &dp, vector<int> &dp2)
    {
        if (i == s.size())
        {
            return 0;
        }

        if (dp2[i] != -1)
        {
            return dp2[i];
        }

        int ans = INT_MAX;
        for (int j = i; j < s.size(); j++)
        {
            if (dp[i][j])
            {
                ans = min(ans, 1 + sol(s, j + 1, dp, dp2));
            }
        }
        return dp2[i] = ans;
    }

    int minCut(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        vector<int> dp2(n + 1, -1);
        for (int L = 1; L <= n; L++)
        {
            for (int i = 0; i + L - 1 < n; i++)
            {
                int j = i + L - 1;
                if (i == j)
                {
                    dp[i][j] = true;
                }
                else if (i + 1 == j)
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
            }
        }

        return sol(s, 0, dp, dp2) - 1;
    }
};