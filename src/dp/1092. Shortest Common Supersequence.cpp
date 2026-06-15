class Solution
{
public:
    int dp[1001][1001];

    int fillDp(string &str1, string &str2, int m, int n)
    {
        if (m == 0 || n == 0)
        {
            return m + n;
        }

        if (dp[m][n] != -1)
        {
            return dp[m][n];
        }

        if (str1[m - 1] == str2[n - 1])
        {
            return dp[m][n] = 1 + fillDp(str1, str2, m - 1, n - 1);
        }
        else
        {
            return dp[m][n] = 1 + min(fillDp(str1, str2, m - 1, n), fillDp(str1, str2, m, n - 1));
        }
    }

    string buildSCS(string &str1, string &str2)
    {
        int m = str1.size();
        int n = str2.size();

        string ans;

        while (m > 0 && n > 0)
        {
            int left = fillDp(str1, str2, m - 1, n);
            int up = fillDp(str1, str2, m, n - 1);
            if (str1[m - 1] == str2[n - 1])
            {
                ans += str1[m - 1];
                m--;
                n--;
            }
            else
            {
                int left = fillDp(str1, str2, m - 1, n);
                int up = fillDp(str1, str2, m, n - 1);

                if (left <= up)
                {
                    ans += str1[m - 1];
                    m--;
                }
                else
                {
                    ans += str2[n - 1];
                    n--;
                }
            }
        }

        while (m > 0)
        {
            ans += str1[m - 1];
            m--;
        }

        while (n > 0)
        {
            ans += str2[n - 1];
            n--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string shortestCommonSupersequence(string str1, string str2)
    {
        memset(dp, -1, sizeof(dp));
        fillDp(str1, str2, str1.size(), str2.size());
        // for(int i = 0; i <= str1.size(); i++)
        // {
        //     for(int j = 0; j <= str2.size(); j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        return buildSCS(str1, str2);
    }
};

class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int dp[1001][1001];
        memset(dp, -1, sizeof(dp));
        int m = str1.size();
        int n = str2.size();
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = i + j;
                }
                else if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // for(int i = 0; i <= str1.size(); i++)
        // {
        //     for(int j = 0; j <= str2.size(); j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        string ans;
        int i = m;
        int j = n;
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                ans.push_back(str1[i - 1]);
                i--;
                j--;
            }
            else
            {
                if (dp[i - 1][j] < dp[i][j - 1])
                {
                    ans.push_back(str1[i - 1]);
                    i--;
                }
                else
                {
                    ans.push_back(str2[j - 1]);
                    j--;
                }
            }
        }

        while (i > 0)
        {
            ans.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0)
        {
            ans.push_back(str2[j - 1]);
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};