class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        if (n == 1)
        {
            return n;
        }
        unordered_map<int, int> m;
        for (const auto &t : trust)
        {
            m[t[1]]++;
        }

        int ans = -1;
        for (auto const &[k, v] : m)
        {
            if (v == n - 1)
            {
                ans = k;
            }
        }

        for (const auto &t : trust)
        {
            if (t[0] == ans)
            {
                return -1;
            }
        }
        return ans;
    }
};