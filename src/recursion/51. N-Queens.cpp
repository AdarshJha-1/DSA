class Solution
{
public:
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        // top
        for (int i = row - 1; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }

        // left top
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        // right top
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }
    void sol(vector<vector<string>> &result, vector<string> &board, int n, int row)
    {
        if (row >= n)
        {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isSafe(board, row, col, n))
            {
                board[row][col] = 'Q';
                sol(result, board, n, row + 1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        sol(result, board, n, 0);
        return result;
    }
};