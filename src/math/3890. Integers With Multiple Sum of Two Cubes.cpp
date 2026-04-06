class Solution
{
public:
    vector<int> findGoodIntegers(int n)
    {
        if (n < 1729)
        {
            return {};
        }
        unordered_map<long long, int> mp;
        vector<int> ans;
        int maxlimit = cbrt(n);
        for (int i = 1; i <= maxlimit; i++)
        {
            for (int j = i; j <= maxlimit; j++)
            {
                long long val = (1LL * i * i * i) + (1LL * j * j * j);
                if (val <= n)
                {
                    mp[val]++;
                }
            }
        }

        for (const auto &mv : mp)
        {
            if (mv.second >= 2)
            {
                ans.push_back(mv.first);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};