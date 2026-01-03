class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        m[0] = 1;
        int ans = 0;
        int sum = 0;
        for (const auto &n : nums)
        {
            sum += n;
            int remain = sum % k;
            if (remain < 0)
                remain += k;
            if (m.find(remain) != m.end())
            {
                ans += m[remain];
            }
            m[remain]++;
        }

        return ans;
    }
};