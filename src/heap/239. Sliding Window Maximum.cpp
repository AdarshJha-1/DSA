class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++)
        {
            pq.push({nums[i], i});
        }

        int n = nums.size();
        vector<int> ans;
        ans.push_back(pq.top().first);

        for (int i = k; i < n; i++)
        {
            pq.push({nums[i], i});
            int startRange = i + 1 - k;

            while (!pq.empty() && !(pq.top().second >= startRange && pq.top().second <= i))
            {
                pq.pop();
            }
            auto [val, idx] = pq.top();
            if (idx >= startRange && idx <= i)
            {
                ans.push_back(val);
            }
        }
        return ans;
    }
};