class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int> ans(adj.size(), -1);
        vector<bool> visited(adj.size(), 0);
        
        queue<int> q;
        q.push(src);
        ans[src] = 0;
        visited[src] = 1;
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            for(int i = 0; i < adj[n].size(); i++) {
                if(!visited[adj[n][i]]) {
                    visited[adj[n][i]] = 1;
                    q.push(adj[n][i]);
                    ans[adj[n][i]] = ans[n] + 1;
                }
            }
        }
        
        return ans;
    }
};
