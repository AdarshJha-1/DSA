class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> m;

        int i = 0, j = 0;
        while (j < n)
        {
            m[nums[j]]++;
            if (m[nums[j]] <= k)
            {
                ans = max(ans, j - i + 1);
            }
            while (m[nums[j]] > k && i < j)
            {
                m[nums[i]]--;
                i++;
            }
            j++;
        }

        return ans;
    }
};