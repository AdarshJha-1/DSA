class Solution
{
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<int>> &grid, int x, int y, int m, int n)
    {
        if (grid[x][y] == 0)
        {
            return;
        }
        grid[x][y] = 2;
        for (auto [_x, _y] : dirs)
        {
            int nx = x + _x;
            int ny = y + _y;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
            {
                dfs(grid, nx, ny, m, n);
            }
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // top
        for (int i = 0; i < n; i++)
        {
            if (grid[0][i] == 1)
            {
                dfs(grid, 0, i, m, n);
            }
        }

        // bottom
        for (int i = 0; i < n; i++)
        {
            if (grid[m - 1][i] == 1)
            {
                dfs(grid, m - 1, i, m, n);
            }
        }

        // left
        for (int i = 1; i < m - 1; i++)
        {
            if (grid[i][0] == 1)
            {
                dfs(grid, i, 0, m, n);
            }
        }

        // right
        for (int i = 1; i < m - 1; i++)
        {
            if (grid[i][n - 1] == 1)
            {
                dfs(grid, i, n - 1, m, n);
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    count++;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    grid[i][j] = 1;
                }
            }
        }

        return count;
    }
};