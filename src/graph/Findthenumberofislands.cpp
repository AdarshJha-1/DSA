class Solution
{
public:
    int countIslands(vector<vector<char>> &grid)
    {
        vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size(), 0));
        queue<pair<int, int>> q;
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (!seen[i][j] && grid[i][j] == 'L')
                {
                    count++;
                    q.push({i, j});
                    seen[i][j] = 1;
                    while (!q.empty())
                    {
                        auto [r, c] = q.front();
                        q.pop();

                        for (int d = 0; d < 8; d++)
                        {
                            int nr = r + dr[d];
                            int nc = c + dc[d];

                            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                                !seen[nr][nc] && grid[nr][nc] == 'L')
                            {
                                seen[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};