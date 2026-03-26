class Solution
{
public:
    vector<int> minMaxCandy(vector<int> &prices, int k)
    {
        sort(prices.begin(), prices.end());
        int minM = 0;
        int maxM = 0;
        int n = prices.size();
        int free = 0;
        for (int i = 0; i < n - free; i++)
        {
            minM += prices[i];
            free += k;
        }

        reverse(prices.begin(), prices.end());
        free = 0;
        for (int i = 0; i < n - free; i++)
        {
            maxM += prices[i];
            free += k;
        }

        return {minM, maxM};
    }
};

class Solution
{
public:
    vector<int> minMaxCandy(vector<int> &prices, int k)
    {
        sort(prices.begin(), prices.end());
        int minM = 0;
        int maxM = 0;
        int n = prices.size();

        int i = 0;
        int j = n - 1;
        while (i <= j)
        {
            minM += prices[i++];
            j -= k;
        }

        i = n - 1;
        j = 0;
        while (i >= j)
        {
            maxM += prices[i--];
            j += k;
        }
        return {minM, maxM};
    }
};
