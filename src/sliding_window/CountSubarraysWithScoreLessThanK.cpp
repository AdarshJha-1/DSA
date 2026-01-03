class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        int i = 0;
        int j = 0;
        long long ans = 0;
        int len = 0;
        long long sum = 0;
        while (j < nums.size())
        {
            sum += nums[j];
            len = j - i + 1;
            while (sum * len >= k && i <= j)
            {
                sum -= nums[i];
                i++;
                len = j - i + 1;
            }
            ans += len;
            j++;
        }

        return ans;
    }
};