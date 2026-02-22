class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto &t : times)
        {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> tt(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        tt[k] = 0;
        tt[0] = 0;

        while (!pq.empty())
        {
            auto [dist, node] = pq.top();
            pq.pop();

            if (dist > tt[node])
                continue;
            for (const auto &nei : adj[node])
            {
                if (dist + nei.second < tt[nei.first])
                {
                    tt[nei.first] = dist + nei.second;
                    pq.push({dist + nei.second, nei.first});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if (tt[i] == INT_MAX)
            {
                return -1;
            }

            ans = max(ans, tt[i]);
        }

        return ans;
    }
};