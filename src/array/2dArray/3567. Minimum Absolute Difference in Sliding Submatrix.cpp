class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        int ansM = (m - k + 1);
        int ansN = (n - k + 1);
        vector<vector<int>> ans(ansM);

        for (int i = 0; i <= m - k; i++)
        {
            for (int j = 0; j <= n - k; j++)
            {
                set<int> st;
                for (int p = i; p < i + k; p++)
                {
                    for (int q = j; q < j + k; q++)
                    {
                        st.insert(grid[p][q]);
                    }
                }

                int minDiff = INT_MAX;
                auto it = st.begin();
                int prevEle = *it;
                it++;
                while (it != st.end())
                {
                    minDiff = min(minDiff, abs(prevEle - *it));
                    prevEle = *it;
                    it++;
                }
                minDiff == INT_MAX ? ans[i].push_back(0) : ans[i].push_back(minDiff);
            }
        }

        return ans;
    }
};