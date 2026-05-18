class Solution 
{
public: 

    int sol(vector<int>& prices, int i, bool holding)
    {
        if(i >= prices.size())
        {
            return 0;
        }

        if(holding) // agar holding hai to sell karungs otherwise buy
        {
            int skip = sol(prices, i + 1, true);
            int sell = sol(prices, i + 1, false) + prices[i];
            return max(skip, sell);
        }
        else
        {
            int skip = sol(prices, i + 1, false);
            int buy = sol(prices, i + 1, true) - prices[i]; 

            return max(skip, buy);
        }

    }

    int maxProfit(vector<int>& prices) 
    {
        return sol(prices, 0, false);
    }
};
