class Solution
{
public:
    int dominantIndices(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> suffix(n, 0);
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = nums[i] + suffix[i + 1];
        }
        int ans = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int avg = (suffix[i + 1] / (n - i - 1));
            if (nums[i] > avg)
            {
                ans++;
            }
        }
        return ans;
    }
};