class Solution {
  public:
  
  
    // DFS approach
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



class Solution {
  public:
  
    // BFS Sol
    bool sol(vector<vector<int>>& adj, vector<bool>& seen, queue<int>& q, vector<int> &parent) {
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            seen[n] = 1;
            for(int i = 0; i < adj[n].size(); i++) {
                if(adj[n][i] == parent[n]) continue;
                if(seen[adj[n][i]]) return 1;
                    parent[adj[n][i]] = n;
                    q.push(adj[n][i]);
            }
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
            if(!seen[i]) {
                queue<int> q;
                vector<int> parent(V, -1);
                q.push(i);
                if(sol(adj, seen, q, parent)) return 1;
            }
        }
        return 0;
    }
};
