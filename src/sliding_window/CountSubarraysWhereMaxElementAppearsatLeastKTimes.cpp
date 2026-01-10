class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        if (k > nums.size())
            return 0;
        int maxEle = *max_element(nums.begin(), nums.end());
        int maxEleCount = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        long long ans = 0;
        while (j < n)
        {
            if (nums[j] == maxEle)
            {
                maxEleCount++;
            }

            while (maxEleCount == k)
            {
                ans += n - j;
                if (nums[i] == maxEle)
                {
                    maxEleCount--;
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};