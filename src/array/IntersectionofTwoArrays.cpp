class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> ans;
        for(auto num : nums1) {
            if(m.find(num) == m.end()) {
                m[num]++;
            }
        }
        for(auto num : nums2) {
            if(m.find(num) != m.end()) {
                m[num]++;
            }
        }

        for(auto it : m) {
            if(it.second >= 2) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
