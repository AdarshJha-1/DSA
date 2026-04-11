class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> m;

        // o(n)
        for (int i = 0; i < n; i++)
        {
            m[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        for (auto &it : m)
        {
            const auto &arr = it.second;
            if (arr.size() >= 3)
            {
                for (int i = 0; i + 2 < arr.size(); i++)
                {
                    ans = min(ans, 2 * (arr[i + 2] - arr[i]));
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};