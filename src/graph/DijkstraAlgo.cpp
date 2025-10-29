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
        
        int loop = V;
        while(loop--) {
            int node = - 1, value = INT_MAX;
            for(int i = 0; i < V; i++) {
                if(!seen[i] && ans[i] < value) {
                    node = i;
                    value = ans[i];
                }
            }
            seen[node] = 1;
            
            for(int i = 0; i < adj[node].size(); i++) {
                if(!seen[adj[node][i].first]) {
                    ans[adj[node][i].first] = min(ans[adj[node][i].first], ans[node] + adj[node][i].second);
                }
            }
        }
        
        return ans;
    }
};
