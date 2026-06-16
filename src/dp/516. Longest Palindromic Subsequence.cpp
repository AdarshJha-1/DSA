class Solution
{
public:
    int dp[1001][1001];

    int solve(string &s, int i, int j)
    {
        if (i > j)
        {
            return 0;
        }
        // only 1 char
        if (i == j)
        {
            return 1;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // if both match then i + 1 and j - 1, also we saw 2 char sp +2 in ans
        if (s[i] == s[j])
        {
            return dp[i][j] = 2 + solve(s, i + 1, j - 1);
        }

        return dp[i][j] = max(solve(s, i + 1, j), solve(s, i, j - 1));
    }

    int longestPalindromeSubseq(string s)
    {
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, s.size() - 1);
    }
};