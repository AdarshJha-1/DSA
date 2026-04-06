class Solution
{
public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &seen, int i, int j, int m, int n)
    {
        if (grid[i][j] == '0')
        {
            return;
        }
        seen[i][j] = true;
        for (auto [x, y] : dir)
        {
            int nx = i + x;
            int ny = j + y;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && !seen[nx][ny] && grid[nx][ny] == '1')
            {
                dfs(grid, seen, nx, ny, m, n);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !seen[i][j])
                {
                    dfs(grid, seen, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};