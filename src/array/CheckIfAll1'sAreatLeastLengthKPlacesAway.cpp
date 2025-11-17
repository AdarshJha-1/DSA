class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastIdxOf1 = -1;
        while (lastIdxOf1 < nums.size() && nums[lastIdxOf1] != 1) {
            lastIdxOf1++;
        };

        for (int i = lastIdxOf1 + 1; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (abs(i - lastIdxOf1 - 1) < k) {
                    return false;
                } else {
                    lastIdxOf1 = i;
                }
            }
        }
        return true;
    }
};
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastIdxOf1 = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (lastIdxOf1 != -1 && abs(i - lastIdxOf1 - 1) < k) {
                    return false;
                } else {
                    lastIdxOf1 = i;
                }
            }
        }
        return true;
    }
};
