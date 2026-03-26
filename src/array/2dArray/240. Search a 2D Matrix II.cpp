class Solution
{
public:
    bool bs(vector<vector<int>> &matrix, int target, int l, int r, int row)
    {
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (matrix[row][m] == target)
            {
                return true;
            }
            else if (matrix[row][m] < target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            int l = 0;
            int r = n - 1;

            if (target >= matrix[i][l] && target <= matrix[i][r])
            {
                if (bs(matrix, target, l, r, i))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size() - 1;
        int n = matrix[0].size() - 1;

        int row = 0;
        int col = n;
        while (row <= m && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (matrix[row][col] > target)
            {
                col--;
            }
            else
            {
                row++;
            }
        }

        return false;
    }
};