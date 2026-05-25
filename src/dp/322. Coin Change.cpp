class Solution {
public:

    vector<int> dp;

    int sol(vector<int>& coins, int amount) 
    {
        if(amount == 0)
        {
            return 0;
        }
        if(dp[amount] != -1)
        {
            return dp[amount];
        }
        int ans = INT_MAX;
        for(int coin : coins)
        {
            if(amount - coin >= 0)
            {
                ans = min(ans + 0LL, (sol(coins, amount - coin) + 1LL));
            }
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        dp.resize(10010, -1);
        int ans = sol(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};
