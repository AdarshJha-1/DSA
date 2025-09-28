class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = nums.size() - 1;
            int target = -1 * nums[i];
            while (j < k) {
                if (nums[j] + nums[k] < target) {
                    j++;
                } else if (nums[j] + nums[k] > target) {
                    k--;
                } else {

                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
            while(i < nums.size() - 2 && nums[i] == nums[i + 1]) i++;
        }
        return ans;
    }
};
