class Solution 
{
public:
    bool isGood(vector<int>& nums) 
    {
        int n = nums.size();
        if(n == 1) return false;
        sort(nums.begin(), nums.end());

        int mn = nums[n - 1];
        for(int i = 0; i < n - 1; i++)
        {
            if(i + 1 != nums[i])
            {
                return false;
            }
        }

        if(nums[n - 1] != mn || nums[n - 2] != mn)
        {
            return false;
        }

        return true;
    }
};
