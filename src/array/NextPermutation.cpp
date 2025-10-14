class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        for(int i = nums.size() - 1; i > 0; i--) {
            if(nums[i] > nums[i - 1]) {
                idx = i - 1;
                break;
            }
        }
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int jidx = -1;
        for(int i = nums.size() - 1; i > idx; i--) {
            if(nums[i] > nums[idx]) {
                jidx = i;
                break;
            }
        }

        swap(nums[idx], nums[jidx]);
        int s = idx + 1, e = nums.size() - 1;
        if(s > nums.size()) return;
        while((s < nums.size() && e < nums.size())&& s < e) {
            swap(nums[s++], nums[e--]);
        } 
    }
};
