class Solution {
  public:
  
  
    bool sol(int n, int p, vector<vector<int>>& adj, vector<bool>& seen) {
        seen[n] = 1;
        for(int i = 0; i < adj[n].size(); i++) {
            if(p == adj[n][i]) continue;
            if(seen[adj[n][i]]) return 1;
            if(sol(adj[n][i], n, adj, seen)) return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        for(auto const &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> seen(V, 0);
        
        for(int i = 0; i < V; i++) {
            if(!seen[i] && sol(i, -1, adj, seen)) return 1;
        }
        return 0;
    }
};
