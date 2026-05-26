class Solution 
{
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

    int countOneFromNeighbors(vector<vector<int>>& board, int r, int c, int m, int n)
    {
        int count = 0;
        for(const auto& d : dir)
        {
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr >= 0 && nr < m && nc >= 0 && nc < n)
            {
                if(board[nr][nc] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) 
    {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> temp = board;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int count = countOneFromNeighbors(board, i, j, m, n);

                if(count < 2 || count > 3)
                {
                    temp[i][j] = 0;
                }
                else
                {
                    if(board[i][j] == 0 && count == 3)
                    {
                        temp[i][j] = 1;
                    }
                }
            }
        }

        board = temp;
    }
};
