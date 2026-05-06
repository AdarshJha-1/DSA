class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &boxGrid)
    {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for (int i = 0; i < m; i++)
        {
            int stoneC = 0;
            int blockIdx = n - 1;
            for (int j = 0; j < n; j++)
            {
                if (boxGrid[i][j] == '#')
                {
                    stoneC++;
                    boxGrid[i][j] = '.';
                }
                else if (boxGrid[i][j] == '*')
                {
                    blockIdx = j;
                    int k = blockIdx - 1;
                    while (stoneC-- && k >= 0)
                    {
                        boxGrid[i][k--] = '#';
                    }
                    blockIdx = j - 1;
                    stoneC = 0;
                }
            }
            int k = blockIdx;
            while (stoneC-- && k >= 0)
            {
                boxGrid[i][k--] = '#';
            }
        }

        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for (int i = 0, k = m - 1; i < m && k >= 0; i++, k--)
        {
            for (int j = 0; j < n; j++)
            {
                ans[j][k] = boxGrid[i][j];
            }
        }
        return ans;
    }
};