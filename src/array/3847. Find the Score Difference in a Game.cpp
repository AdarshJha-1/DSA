class Solution
{
public:
    int scoreDifference(vector<int> &nums)
    {
        int n = nums.size();
        int active = 0;
        vector<int> ans(2, 0);

        for (int i = 0; i < n; i++)
        {
            if ((i + 1) % 6 == 0)
            {
                active = 1 - active;
            }
            if (nums[i] % 2 != 0)
            {
                active = 1 - active;
            }
            ans[active] += nums[i];
        }

        return ans[0] - ans[1];
    }
};