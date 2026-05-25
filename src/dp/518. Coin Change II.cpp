class Solution 
{
public:
    vector<vector<int>> dp;

    int sol(int amount, vector<int>& coins, int idx) 
    {
        if(amount == 0)
        {
            return 1;
        }
        if(dp[idx][amount] != -1)
        {
            return dp[idx][amount];
        }
        int ans = 0;
        for(int i = idx; i < coins.size(); i++)
        {
            if(amount - coins[i] >= 0)
            {
                ans += sol(amount - coins[i], coins, i);
            }
        }

        return dp[idx][amount] = ans;
    }

    int change(int amount, vector<int>& coins) 
    {
        dp.resize(coins.size() + 1, vector<int>(amount + 1, -1));
        return sol(amount, coins, 0);
    }
};
class Solution 
{
public:
    vector<vector<int>> dp;

    int sol(int amount, vector<int>& coins, int idx) 
    {
        if(amount == 0)
        {
            return 1;
        }

        if(amount < 0)
        {
            return 0;
        }

        if(idx >= coins.size())
        {
            return 0;
        }

        if(dp[idx][amount] != -1)
        {
            return dp[idx][amount];
        }

        return dp[idx][amount] = sol(amount - coins[idx], coins, idx) + sol(amount, coins, idx + 1);

    }

    int change(int amount, vector<int>& coins) 
    {
        dp.resize(coins.size() + 1, vector<int>(amount + 1, -1));
        return sol(amount, coins, 0);
    }
};
