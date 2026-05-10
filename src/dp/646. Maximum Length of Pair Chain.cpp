class Solution 
{
public:

    vector<vector<int>> dp;

    int sol(vector<vector<int>>& pairs, int n, int i, int prev)
    {
        if(i >= n)
        {
            return 0;
        }

        if(prev != -1 && dp[i][prev] != -1)
        {
            return dp[i][prev];
        }

        int skip = sol(pairs, n, i + 1, prev);
        int take = 0;
        if(prev == -1 || pairs[i][0] > pairs[prev][1])
        {
            take = sol(pairs, n, i + 1, i) + 1;
        }
        if(prev != -1)
        {
            return dp[i][prev] = max(skip, take);
        }

        return max(skip, take);
    }

    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        dp.resize(1001, vector<int>(1001, -1));
        return sol(pairs, n, 0, -1);
    }
};
class Solution 
{
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(), pairs.end());
        int n = pairs.size();
        vector<int> dp(n, 1);

        int ans = 1;

        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(pairs[i][0] > pairs[j][1])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
