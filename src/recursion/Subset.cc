class Solution {
public:
  void subs(vector<int> &nums, int i, vector<vector<int>> &ans,
            vector<int> temp) {

    if (i == nums.size()) {
      ans.push_back(temp);
      return;
    }
    // no
    subs(nums, i + 1, ans, temp);
    // yes
    temp.push_back(nums[i]);
    subs(nums, i + 1, ans, temp);
  }
  vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    subs(nums, 0, ans, temp);
    return ans;
  }
};
