class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> backProPref(n, 1), forwProSuff(n, 1);

        backProPref[0] = nums[0], forwProSuff[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++)
        {
            backProPref[i] = nums[i] * backProPref[i - 1];
        }
        for(int i = n - 2; i >= 0; i--)
        {
            forwProSuff[i] = nums[i] * forwProSuff[i + 1];
        }

        vector<int> ans(n, 0);
        ans[0] = forwProSuff[1];
        ans[n - 1] = backProPref[n - 2];

        for(int i = 1; i < n - 1; i++)
        {
            ans[i] = forwProSuff[i + 1] * backProPref[i - 1];
        }
    
        return ans;
    }
};
