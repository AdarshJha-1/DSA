class Solution 
{
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < n; i++)
        {
            int x1 = points[i][0], y1 = points[i][1]; 
            for(int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});

            }
        }

        int sum = 0;
        vector<bool> inMST(n, false);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, -1}});

        while(!pq.empty())
        {
            auto [wei, temp] = pq.top();
            pq.pop();
            auto [node, pare] = temp;

            if(!inMST[node])
            {
                inMST[node] = true;
                sum += wei;

                for(const auto& nei : adj[node])
                {
                    if(!inMST[nei.first])
                    {
                        pq.push({nei.second, {nei.first, node}});
                    }
                }
            }
        }

        return sum;
    }
};
