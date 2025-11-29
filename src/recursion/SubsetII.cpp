class Solution {
public:

    void sol(vector<int>& arr, int idx, set<vector<int>>& s, vector<int>& temp) {
        if(idx == arr.size()) {
            s.insert(temp);
            return;
        }
        temp.push_back(arr[idx]);
        sol(arr, idx + 1, s, temp);
        temp.pop_back();
        sol(arr, idx + 1, s, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<int> temp;
        sol(nums, 0, s, temp);
        vector<vector<int>> ans;
        for(const auto& v : s) {
            ans.push_back(v);
        }
        return ans;
    }
};
