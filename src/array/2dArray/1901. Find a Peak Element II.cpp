class Solution
{
public:
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isValid(vector<vector<int>> &mat, int i, int j, int m, int n)
    {
        for (const auto &d : dir)
        {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n && mat[ni][nj] > mat[i][j])
            {
                return false;
            }
        }
        return true;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        // brute-force
        vector<int> ans(2, -1);
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isValid(mat, i, j, m, n))
                {
                    ans[0] = i;
                    ans[1] = j;
                    break;
                }
            }
        }
        return ans;
    }
};