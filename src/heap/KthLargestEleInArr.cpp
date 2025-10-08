class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // O(nlogn) -> sort
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }

    int findKthLargestv1(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto &n : nums) {
            pq.push(n);
        }
        int ans = 0;
        while(k--) {
            ans = pq.top();
            pq.pop();
        }

        return ans;
    }
};


