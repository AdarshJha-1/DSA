class Solution
{
public:
    void sol(vector<vector<int>> &maze, int i, int j, vector<string> &ans, int n, string &temp)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(temp);
            return;
        }
        maze[i][j] = 0;

        // U
        if (i - 1 >= 0 && maze[i - 1][j] != 0)
        {
            temp.push_back('U');
            sol(maze, i - 1, j, ans, n, temp);
            temp.pop_back();
        }
        // D
        if (i + 1 < n && maze[i + 1][j] != 0)
        {
            temp.push_back('D');
            sol(maze, i + 1, j, ans, n, temp);
            temp.pop_back();
        }
        // L
        if (j - 1 >= 0 && maze[i][j - 1] != 0)
        {
            temp.push_back('L');
            sol(maze, i, j - 1, ans, n, temp);
            temp.pop_back();
        }
        // R
        if (j + 1 < n && maze[i][j + 1] != 0)
        {
            temp.push_back('R');
            sol(maze, i, j + 1, ans, n, temp);
            temp.pop_back();
        }
        maze[i][j] = 1;
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        vector<string> ans;
        if (maze[0][0] == 0)
        {
            return ans;
        }
        int n = maze.size();
        if (maze[n - 1][n - 1] == 0)
        {
            return ans;
        }
        string temp = "";
        sol(maze, 0, 0, ans, n, temp);
        sort(ans.begin(), ans.end());
        return ans;
    }
};