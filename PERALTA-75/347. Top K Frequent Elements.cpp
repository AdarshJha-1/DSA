class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> m;
        for (const auto &num : nums)
        {
            m[num]++;
        }

        for (const auto &it : m)
        {
            pq.push({it.second, it.first});
        }

        vector<int> ans;
        while (k-- && !pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};