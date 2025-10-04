class Solution {
public:
    bool isInc(vector<int>& nums, int s, int e) {
        for (int i = s; i < e; i++) {
            if (nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }

    bool isDec(vector<int>& nums, int s, int e) {
        for (int i = s; i < e; i++) {
            if (nums[i] <= nums[i + 1])
                return false;
        }
        return true;
    }

    long long  sum(vector<int>& nums, int s, int e) {
        long long  sum = 0;
        for (int i = s; i <= e; i++) {
            sum += nums[i];
        }
        return sum;
    }

    long long splitArray(vector<int>& nums) {
        int i = 0, s = 0, e = nums.size() - 1;
        long long ans = -1;
        for (int i = 0; i < e; i++) {
            if (isInc(nums, s, i) && isDec(nums, i + 1, e)) {
                if (ans == -1) {
                    ans = INT_MAX;
                }
                long long diff = abs(sum(nums, s, i) - sum(nums, i + 1, e));
                ans = min(ans, diff);
            }
        }
        return ans;
    }
};
