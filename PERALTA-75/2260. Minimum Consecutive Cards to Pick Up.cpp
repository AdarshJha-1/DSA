class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> m;
        int ans = INT_MAX;
        int i = 0;
        for (int j = 0; j < cards.size(); j++)
        {
            m[cards[j]]++;
            while (m[cards[j]] > 1)
            {
                ans = min(ans, (j - i + 1));
                m[cards[i++]]--;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};