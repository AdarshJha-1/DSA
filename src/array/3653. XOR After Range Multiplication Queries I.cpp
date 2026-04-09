class Solution
{
public:
    int xorAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        const int MOD = 1000000007;
        for (const auto &q : queries)
        {
            int idx = q[0];
            while (idx <= q[1])
            {
                nums[idx] = (1LL * nums[idx] * q[3]) % MOD;
                idx += q[2];
            }
        }

        int ans = 0;
        for (const auto &n : nums)
        {
            ans ^= n;
        }

        return ans;
    }
};