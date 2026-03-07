class Solution
{
public:
    bool isValid(vector<vector<int>> &mat, int r, int c)
    {
        for (int i = r - 1; i >= 0; i--)
        {
            if (mat[i][c] == 1)
            {
                return false;
            }
        }
        for (int i = r + 1; i < mat.size(); i++)
        {
            if (mat[i][c] == 1)
            {
                return false;
            }
        }
        for (int i = c - 1; i >= 0; i--)
        {
            if (mat[r][i] == 1)
            {
                return false;
            }
        }
        for (int i = c + 1; i < mat[r].size(); i++)
        {
            if (mat[r][i] == 1)
            {
                return false;
            }
        }

        return true;
    }
    int numSpecial(vector<vector<int>> &mat)
    {
        int count = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1 && isValid(mat, i, j))
                {
                    count++;
                }
            }
        }

        return count;
    }
};