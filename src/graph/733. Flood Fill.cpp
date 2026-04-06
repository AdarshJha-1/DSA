class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        queue<pair<int, int>> q;
        q.push({sr, sc});

        int m = image.size();
        int n = image[0].size();

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        int spc = image[sr][sc];
        image[sr][sc] = color;
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (const auto &[_x, _y] : dirs)
            {
                int nx = x + _x;
                int ny = y + _y;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] != color && image[nx][ny] == spc)
                {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};