class Solution 
{
  public:
    using dt = pair<int, pair<int, int>>;
  
    int spanningTree(int V, vector<vector<int>>& edges) 
    {
        
        vector<vector<pair<int, int>>> adj(V);
        for(const auto& e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        
        int sum = 0;
        vector<bool> inMST(V, false);
        priority_queue<dt, vector<dt>, greater<dt>> pq;
        pq.push({0, {0, -1}});
        
        while(!pq.empty())
        {
            auto [wei, dv] = pq.top();
            pq.pop();
            auto [node, par] = dv;
            
            if(inMST[node])
            {
                continue;
            }
            
            
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
        
        return sum;
    }
};
