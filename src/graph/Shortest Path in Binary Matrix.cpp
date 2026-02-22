class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == 1)
        {
            return -1;
        }

        vector<vector<int>> directions{
            {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        grid[0][0] = 1;

        while (!pq.empty())
        {
            auto [d, curr] = pq.top();
            auto [x, y] = curr;
            pq.pop();

            for (const auto dir : directions)
            {
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && grid[new_x][new_y] != 1 && d + 1 < dist[new_x][new_y])
                {
                    dist[new_x][new_y] = d + 1;
                    pq.push({dist[new_x][new_y], {new_x, new_y}});
                }
            }
        }

        return dist[n - 1][m - 1] != INT_MAX ? dist[n - 1][m - 1] + 1 : -1;
    }
};