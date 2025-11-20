class Solution {
public:
    int partition(vector<int>& nums, int s, int e) {
        int pos = s;
        for(int i = s; i <= e; i++) {
            if(nums[i] <= nums[e]) {
                swap(nums[pos], nums[i]);
                pos++;
            }
        }

        return pos - 1;
    }

    void quick_sort(vector<int>& nums, int s, int e) {
        if (s >= e)
            return;
        int pivot = partition(nums, s, e);
        quick_sort(nums, s, pivot - 1);
        quick_sort(nums, pivot + 1, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        quick_sort(nums, s, e);
        return nums;
    }
};
