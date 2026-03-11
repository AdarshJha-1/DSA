class Solution
{
public:
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        ans[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            auto [c, curr] = pq.top();
            auto [i, j] = curr;
            pq.pop();

            if (i == m - 1 && j == n - 1)
            {
                return c;
            }
            if (c > ans[i][j])
            {
                continue;
            }
            for (const auto d : dir)
            {
                int ni = i + d[0];
                int nj = j + d[1];
                if (ni >= 0 && nj >= 0 && ni < m && nj < n)
                {
                    int diff = abs(heights[i][j] - heights[ni][nj]);
                    int toStore = max(c, diff);
                    if (toStore < ans[ni][nj])
                    {
                        ans[ni][nj] = toStore;
                        pq.push({toStore, {ni, nj}});
                    }
                }
            }
        }

        return ans[m - 1][n - 1];
    }
};