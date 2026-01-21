class Solution
{
public:
    long long maximumScore(vector<int> &nums)
    {
        int n = nums.size();

        vector<long long> preSum(n, 0);
        preSum[0] = nums[0];

        vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
        {
            preSum[i] = nums[i] + preSum[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        long long ans = INT_MIN;
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(ans, (preSum[i] - suffMin[i + 1]));
        }

        return ans;
    }
};