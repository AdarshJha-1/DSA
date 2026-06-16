class Solution
{
public:
    int dp[501][501];

    int sol(string &w1, string &w2, int i, int j)
    {
        // if w2 end then i have to delete w1 remaing char or if w1 end then i have to insert remaing char to make w2 so this is how base case works....right ?
        if (i == w1.size())
        {
            return w2.size() - j;
        }
        if (j == w2.size())
        {
            return w1.size() - i;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (w1[i] == w2[j])
        {
            return dp[i][j] = sol(w1, w2, i + 1, j + 1);
        }
        else
        {

            // replace
            int ans = 1 + sol(w1, w2, i + 1, j + 1);

            // delete
            ans = min(ans, 1 + sol(w1, w2, i + 1, j));

            // insert
            ans = min(ans, 1 + sol(w1, w2, i, j + 1));

            return dp[i][j] = ans;
        }
    }

    int minDistance(string word1, string word2)
    {
        memset(dp, -1, sizeof(dp));
        return sol(word1, word2, 0, 0);
    }
};

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int dp[501][501];
        memset(dp, -1, sizeof(dp));
        int m = word1.size();
        int n = word2.size();

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = j;
                }
                else if (j == 0)
                {
                    dp[i][j] = i;
                }
                else if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
                }
            }
        }

        return dp[m][n];
    }
};