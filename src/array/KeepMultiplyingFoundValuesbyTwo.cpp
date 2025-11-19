class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool arr[1001];
        for(int i = 0; i < nums.size(); i++) {
            arr[nums[i]] = true;
        }

        while(original < 1001 && arr[original]) {
            original *= 2;
        }

        return original;
    }
};
