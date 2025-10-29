// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        vector<int> ans(V, INT_MAX);
        vector<bool> seen(V, 0);
        
        ans[src] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while(!pq.empty()) {
            int node = pq.top().second, value = pq.top().first;
            pq.pop();
            
            if(seen[node]) continue;
            
            seen[node] = 1;
            for(int i = 0; i < adj[node].size(); i++) {
                if(!seen[adj[node][i].first] && ans[node] + adj[node][i].second < ans[adj[node][i].first]) {
                    ans[adj[node][i].first] = ans[node] + adj[node][i].second;
                    pq.push({ans[adj[node][i].first], adj[node][i].first});
                }
            }
        }
        
        return ans;
    }
};
