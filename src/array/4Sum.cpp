class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2;)
            {
                int l = j + 1;
                int r = n - 1;
                long long want = (long long)target - (long long)nums[i] - (long long)nums[j];
                while (l < r)
                {
                    long long temp = (long long)nums[l] + (long long)nums[r];
                    if (temp < want)
                    {
                        l++;
                    }
                    else if (temp > want)
                    {
                        r--;
                    }
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < n && nums[l] == nums[l - 1])
                            l++;
                    }
                }

                j++;
                while (j < n && nums[j] == nums[j - 1])
                    j++;
            }
        }
        return ans;
    }
};