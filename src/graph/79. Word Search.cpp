class Solution
{
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<bool>> seen;
    void sol(vector<vector<char>> &board, string word, int wi, int r, int c, int m, int n, bool &ans)
    {
        if (wi == word.size())
        {
            ans = true;
            return;
        }
        seen[r][c] = true;
        if (board[r][c] == word[wi])
        {
            // here we check if the len is only 1 of board and word, as if we have valid match but the word is of len 1 and also the board so no point in checking furtur...the code doesn't say len 1 but let;s say if len in only 1 or the leave the len = 1 part if the current word which is valid is last word we have to check so we can write ans as true no furthur check needed
            if (wi == word.size() - 1)
            {
                ans = true;
                return;
            }
            for (const auto &d : dir)
            {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !seen[nr][nc])
                {
                    sol(board, word, wi + 1, nr, nc, m, n, ans);
                }
            }
        }
        else
        {
            // here we return as if a valid state is passing but a invalid state occured then we can;t checl furthur so we backtrack
            seen[r][c] = false;
            return;
        }

        // we still have to backtrack for all the valid cases
        seen[r][c] = false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        seen.resize(m, vector<bool>(n, false));
        bool ans = false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sol(board, word, 0, i, j, m, n, ans);
            }
        }

        return ans;
    }
};