class Solution {
  public:
  
    bool sol(int n, vector<vector<int>>& adj, vector<bool>& seen, vector<bool>& path) {
        seen[n] = 1;
        path[n] = 1;
        for(int i = 0; i < adj[n].size(); i++) {
            if(path[adj[n][i]]) return 1;
            if (!seen[adj[n][i]] && sol(adj[n][i], adj, seen, path)) return true;
        }
        path[n] = 0;
        return 0;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for(auto e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        vector<bool> seen(V, 0);
        vector<bool> path(V, 0);
        for(int i = 0; i < V; i++) {
            if(!seen[i] && sol(i, adj, seen, path)) return 1;
        }
        return 0;
    }
};
