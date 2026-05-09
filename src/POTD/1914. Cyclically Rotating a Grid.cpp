class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < min(n, m) / 2; i++)
        {
            vector<int> temp;
            // top
            for (int j = i; j < n - i; j++)
            {
                temp.push_back(grid[i][j]);
            }

            // right
            for (int j = i + 1; j < m - i; j++)
            {
                temp.push_back(grid[j][n - i - 1]);
            }

            // bottom
            for (int j = n - 2 - i; j >= i; j--)
            {
                temp.push_back(grid[m - 1 - i][j]);
            }

            // left
            for (int j = m - 2 - i; j > i; j--)
            {
                temp.push_back(grid[j][i]);
            }

            // reentring values

            long s = temp.size();
            long idx = k % s;

            // top
            for (int j = i; j < n - i; j++)
            {
                grid[i][j] = temp[idx % s];
                idx++;
            }

            // right
            for (int j = i + 1; j < m - i; j++)
            {
                grid[j][n - i - 1] = temp[idx % s];
                idx++;
            }

            // bottom
            for (int j = n - 2 - i; j >= i; j--)
            {
                grid[m - 1 - i][j] = temp[idx % s];
                idx++;
            }

            // left
            for (int j = m - 2 - i; j > i; j--)
            {
                grid[j][i] = temp[idx % s];
                idx++;
            }
        }
        return grid;
    }
};