class Solution
{
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>> &board, int x, int y, int m, int n)
    {
        if (board[x][y] == 'X')
        {
            return;
        }
        board[x][y] = 'T';
        for (auto [_x, _y] : dirs)
        {
            int nx = x + _x;
            int ny = y + _y;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O')
            {
                dfs(board, nx, ny, m, n);
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        // top
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(board, 0, i, m, n);
            }
        }

        // bottom
        for (int i = 0; i < n; i++)
        {
            if (board[m - 1][i] == 'O')
            {
                dfs(board, m - 1, i, m, n);
            }
        }

        // left
        for (int i = 1; i < m - 1; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0, m, n);
            }
        }

        // right
        for (int i = 1; i < m - 1; i++)
        {
            if (board[i][n - 1] == 'O')
            {
                dfs(board, i, n - 1, m, n);
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'T')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};