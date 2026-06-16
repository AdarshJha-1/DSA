class Solution
{
public:
    int dp[1001][1001];

    bool isP(string &s, int i, int j)
    {
        if (i > j)
        {
            return true;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s[i] == s[j])
        {
            return dp[i][j] = isP(s, i + 1, j - 1);
        }

        return dp[i][j] = false;
    }
    string longestPalindrome(string s)
    {
        memset(dp, -1, sizeof(dp));
        int startIdx = 0;
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (isP(s, i, j))
                {
                    int currLen = j - i + 1;
                    if (currLen > maxLen)
                    {
                        maxLen = currLen;
                        startIdx = i;
                    }
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }
};