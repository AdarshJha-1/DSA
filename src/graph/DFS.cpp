class Solution {
  public:
  
    void DFS(int node, vector<vector<int>>& adj, vector<int>& ans, vector<bool>& seen) {
        seen[node] = 1;
        ans.push_back(node);
        for(int i = 0; i < adj[node].size(); i++) {
            if(!seen[adj[node][i]]) {
                DFS(adj[node][i], adj, ans, seen);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans;
        vector<bool> seen(adj.size(), 0);
        DFS(0, adj, ans, seen);
        return ans;
    }
};
