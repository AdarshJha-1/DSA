class Solution
{
public:
    void sol(vector<vector<int>> &ans, vector<int> &nums, int idx)
    {
        if (idx >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> us;
        for (int i = idx; i < nums.size(); i++)
        {
            if (us.count(nums[i]) == 0)
            {
                us.insert(nums[i]);
                swap(nums[i], nums[idx]);
                sol(ans, nums, idx + 1);
                swap(nums[i], nums[idx]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sol(ans, nums, 0);
        return ans;
    }
};