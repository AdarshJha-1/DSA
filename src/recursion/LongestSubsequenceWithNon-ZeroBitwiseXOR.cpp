#include <algorithm>

class Solution {
public:
    void sol(vector<int>& nums, int& ans, int& x, int s, int i, int n) {
        if (i == n) {
            if (x != 0)
                ans = max(ans, s);
            return;
        };

        x ^= nums[i];
        sol(nums, ans, x, s + 1, i + 1, n);
        x ^= nums[i];
        sol(nums, ans, x, s, i + 1, n);
    }

    int longestSubsequence(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int x = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            x ^= nums[i];
        }

        int ans = 0;
        x = 0;
        sol(nums, ans, x, 0, 0, nums.size());
        return ans;
    }
};
