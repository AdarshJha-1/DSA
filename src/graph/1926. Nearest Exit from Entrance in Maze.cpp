class Solution 
{
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        int counter = 0;
        q.push({entrance[0], entrance[1]});
        seen[entrance[0]][entrance[1]] = true;
        while(!q.empty())
        {
            int s = q.size();
            while(s--)
            {
                auto [r, c] = q.front();
                q.pop();
                if(!(r == entrance[0] && c == entrance[1]) && (r == 0 || r == m - 1 || c == 0 || c == n - 1))
                {
                    return counter;
                }
                else
                {
                    for(const auto& d : dir)
                    {
                        int nr = r + d[0];
                        int nc = c + d[1];
                        if(nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr][nc] == '.' && !seen[nr][nc])
                        {
                            q.push({nr, nc});
                            seen[nr][nc] = true;
                        }
                    }
                }
            }
            counter++;
        }   

        return -1;     
    }
};
