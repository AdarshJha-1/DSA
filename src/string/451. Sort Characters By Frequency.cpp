class Solution
{
public:
    string frequencySort(string s)
    {
        vector<int> arr(256, 0);
        for (const auto &c : s)
        {
            arr[c]++;
        }
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 256; i++)
        {
            if (arr[i] > 0)
            {
                pq.push({arr[i], i});
            }
        }

        string ans = "";
        while (!pq.empty())
        {
            int time = pq.top().first;
            while (time--)
            {
                ans += pq.top().second;
            }
            pq.pop();
        }

        return ans;
    }
};