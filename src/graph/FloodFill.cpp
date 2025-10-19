class Solution {
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        vector<vector<bool>> seen(image.size(), vector<bool>(image[0].size(), 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int startColor = image[sr][sc];
        while(!q.empty()) {
            const auto&[i, j] = q.front();
            q.pop();
            if(seen[i][j] == 1) continue;
            if(image[i][j] == startColor) {
                image[i][j] = color;
                seen[i][j] = 1;
                if(j - 1 >= 0) {
                    q.push({i, j - 1});
                }
                if(j + 1 < image[i].size()) {
                    q.push({i, j + 1});
                }
                if(i - 1 >= 0) {
                    q.push({i -1, j});
                }
                if(i + 1 < image.size()) {
                    q.push({i + 1, j});
                }
            }
        }
        return image;
    }
};
