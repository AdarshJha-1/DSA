class Solution 
{
public: 

    vector<int> holdingDP;
    vector<int> notHoldingDP;

    int sol(vector<int>& prices, int i, bool holding)
    {
        if(i >= prices.size())
        {
            return 0;
        }

        if(holding) // agar holding hai to sell karungs otherwise buy
        {
            if(holdingDP[i] != -1)
            {
                return holdingDP[i];
            }
            int skip = sol(prices, i + 1, true);
            int sell = sol(prices, i + 1, false) + prices[i];
            return holdingDP[i] = max(skip, sell);
        }
        else
        {
            if(notHoldingDP[i] != -1)
            {
                return notHoldingDP[i];
            }   
            int skip = sol(prices, i + 1, false);
            int buy = sol(prices, i + 1, true) - prices[i]; 

            return notHoldingDP[i] = max(skip, buy);
        }

    }

    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        holdingDP.resize(n, -1);
        notHoldingDP.resize(n, -1);
        return sol(prices, 0, false);
    }
};
