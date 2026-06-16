class Solution
{
public:
    bool isPal(string &str, int i, int j)
    {
        while (i <= j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int countSubstrings(string s)
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (isPal(s, i, j))
                {
                    count++;
                }
            }
        }
        return count;
    }
};
class Solution
{
public:
    // bool isPal(string &str, int i, int j)
    // {
    //     while(i <= j)
    //     {
    //         if(str[i] != str[j])
    //         {
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }

    // with rec + memo

    int dp[1001][1001];

    bool isPal(string &str, int i, int j)
    {
        if (i > j)
        {
            return true;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (str[i] == str[j])
        {
            return dp[i][j] = isPal(str, i + 1, j - 1);
        }
        return dp[i][j] = false;
    }

    int countSubstrings(string s)
    {
        memset(dp, -1, sizeof(dp));
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (isPal(s, i, j))
                {
                    count++;
                }
            }
        }
        return count;
    }
};