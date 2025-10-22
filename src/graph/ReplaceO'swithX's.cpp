// User function Template for C++

class Solution
{
public:
    int n;
    int m;

    bool isValid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    void dfs(vector<vector<char>> &mat, int i, int j)
    {
        mat[i][j] = 'T';
        int rd[] = {0, 0, -1, 1};
        int cd[] = {-1, 1, 0, 0};
        for (int k = 0; k < 4; k++)
        {
            int r = i + rd[k];
            int c = j + cd[k];

            if (isValid(r, c) && mat[r][c] != 'T' && mat[r][c] == 'O')
            {
                dfs(mat, r, c);
            }
        }
    }

    vector<vector<char>> fill(vector<vector<char>> &mat)
    {
        n = mat.size();
        m = mat[0].size();

        // top row
        for (int i = 0; i < m; i++)
        {
            if (mat[0][i] == 'O')
            {
                dfs(mat, 0, i);
            }
        }

        // down row
        for (int i = 0; i < m; i++)
        {
            if (mat[n - 1][i] == 'O')
            {
                dfs(mat, n - 1, i);
            }
        }

        // left col
        for (int i = 1; i < n - 1; i++)
        {
            if (mat[i][0] == 'O')
            {
                dfs(mat, i, 0);
            }
        }
        // right col
        for (int i = 1; i < n - 1; i++)
        {
            if (mat[i][m - 1] == 'O')
            {
                dfs(mat, i, m - 1);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O')
                    mat[i][j] = 'X';
                if (mat[i][j] == 'T')
                    mat[i][j] = 'O';
            }
        }

        return mat;
    }
};