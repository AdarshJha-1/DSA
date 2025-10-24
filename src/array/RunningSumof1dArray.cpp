class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int currSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            nums[i] += currSum;
            currSum = nums[i];
        }
        return nums;
    }
};
