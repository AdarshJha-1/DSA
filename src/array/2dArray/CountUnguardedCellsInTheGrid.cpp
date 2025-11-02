class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> mat(m, vector<char>(n, '0'));
        for(auto g : guards) mat[g[0]][g[1]] = 'G';
        for(auto w : walls) mat[w[0]][w[1]] = 'W';

        for(auto g : guards) {
            int r = g[0], c = g[1];
            // up
            int i = r - 1;
            while(i >= 0 && mat[i][c] != 'W')  mat[i--][c] = '1';
            
            // down
            i = r + 1;
            while(i < m && mat[i][c] != 'W') mat[i++][c] = '1';

            // left
            int j = c - 1;
            while(j >= 0 && mat[r][j] != 'W') mat[r][j--] = '1';

            // right
            j = c + 1;
            while(j < n && mat[r][j] != 'W') mat[r][j++] = '1';
        }

        int ans = 0;
        for(auto r : mat) {
            for(auto c : r) {
                if(c == '0') ans++;
            }
        }

        return ans;
    }
};
