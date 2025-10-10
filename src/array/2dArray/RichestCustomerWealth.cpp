class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(auto &r : accounts) {
            int sum = 0;
            for(auto &c : r) {
                sum += c;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
