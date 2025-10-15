class Solution {
public:
    int reversePairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int idx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[idx] * 2 < nums[i]) count++;
        }
        return count;
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] > nums[j] * 2) count++;
            }
        }
        return count;
    }
};
