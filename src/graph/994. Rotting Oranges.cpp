class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty())
        {
            int s = q.size();
            while (s--)
            {
                auto [x, y] = q.front();
                q.pop();
                for (auto [_x, _y] : dirs)
                {
                    int nx = x + _x;
                    int ny = y + _y;

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            count++;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return count == 0 ? 0 : count - 1;
    }
};