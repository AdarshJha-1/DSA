class Solution
{
public:
    int dp[501][501];

    int sol(string &s1, string &s2, int i, int j)
    {
        if (i == s1.size())
        {
            return s2.size() - j;
        }
        if (j == s2.size())
        {
            return s1.size() - i;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s1[i] == s2[j])
        {
            return dp[i][j] = sol(s1, s2, i + 1, j + 1) + 1;
        }
        else
        {
            int takeI = sol(s1, s2, i + 1, j) + 1;
            int takeJ = sol(s1, s2, i, j + 1) + 1;
            return dp[i][j] = min(takeI, takeJ);
        }
    }

    int minSuperSeq(string &s1, string &s2)
    {
        memset(dp, -1, sizeof(dp));
        return sol(s1, s2, 0, 0);
    }
};