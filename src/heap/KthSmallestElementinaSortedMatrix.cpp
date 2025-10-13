class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 1 && k == 1) return matrix[0][0];
        int n = matrix.size();
        int s = matrix[0][0];
        int e = matrix[n - 1][n - 1];
        while(s < e) {
            int m = s + (e - s) / 2;
            int c = 0;
            for(auto &r : matrix) {
                c += upper_bound(r.begin(), r.end(), m) - r.begin();
            }

            if(c >= k) {
                e = m;
            } else {
                s = m + 1;
            }
        }
        return s;
    }
};
