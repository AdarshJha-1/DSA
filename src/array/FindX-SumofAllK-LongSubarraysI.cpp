class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        for (int i = 0; i <= nums.size() - k; i++) {
            int j = i + k - 1;
            vector<int> temp(51, 0);
            for (int idx = i; idx <= j; idx++) {
                temp[nums[idx]]++;
            }

            priority_queue<pair<int, int>> pq;
            for (int f = 1; f < 51; f++) {
                if (temp[f] > 0) {
                    pq.push({temp[f], f});
                }
            }
            int t = x;
            int a = 0;
            while (t-- && !pq.empty()) {
                a += pq.top().first * pq.top().second;
                pq.pop();
            }
            ans.push_back(a);
        }
        return ans;
    }
};
