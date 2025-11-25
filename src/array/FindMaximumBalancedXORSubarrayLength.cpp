class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        vector<vector<int>> subarray;
        for(int i = 0; i < nums.size(); i++) {
            int odd = 0, even = 0;
            vector<int> temp;
            int res = 0;
            for(int j = i; j < nums.size(); j++) {
                nums[j] % 2 == 0 ? even++ : odd++;
                res ^= nums[j];
                temp.push_back(nums[j]);
                if(temp.size() > 1 && res == 0 && even == odd) {
                    subarray.push_back(temp);
                }
            }
        }

        int ans = 0;
        for(auto v : subarray) {
            if(v.size() > ans) {
                ans = v.size();
            }
        }
        return ans;
    }
};


class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int odd = 0, even = 0;
            int res = 0;
            for(int j = i; j < nums.size(); j++) {
                nums[j] % 2 == 0 ? even++ : odd++;
                res ^= nums[j];
                if((j - i + 1) > 1 && res == 0 && even == odd) {
                    ans = max(ans, (j - i + 1));
                }
            }
        }
        return ans;
    }
};
