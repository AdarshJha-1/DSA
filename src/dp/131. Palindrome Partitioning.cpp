class Solution
{
public:
    void sol(string &s, int i, vector<vector<bool>> &dp, vector<string> &part, vector<vector<string>> &ans)
    {
        if (i == s.size())
        {
            ans.push_back(part);
            return;
        }

        for (int j = i; j < s.size(); j++)
        {
            if (dp[i][j])
            {
                part.push_back(s.substr(i, j - i + 1));
                sol(s, j + 1, dp, part, ans);
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));

        for (int l = 1; l <= n; l++)
        {
            for (int i = 0; i + l - 1 < n; i++)
            {
                int j = i + l - 1;
                if (i == j)
                {
                    dp[i][j] = 1;
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

        vector<string> part;
        vector<vector<string>> ans;

        sol(s, 0, dp, part, ans);

        return ans;
    }
};