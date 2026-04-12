class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            if (target >= matrix[i][0] && target <= matrix[i][n - 1])
            {
                int s = 0;
                int e = n - 1;
                while (s <= e)
                {
                    int m = s + (e - s) / 2;
                    int val = matrix[i][m];
                    if (val == target)
                    {
                        return true;
                    }
                    else if (val > target)
                    {
                        e = m - 1;
                    }
                    else
                    {
                        s = m + 1;
                    }
                }
            }
        }
        return false;
    }
};