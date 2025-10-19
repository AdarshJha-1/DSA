// DFS Approach
class Solution {
  public:
    
    void sol(int n, vector<vector<int>>& adj, vector<bool>& seen, stack<int>& st) {
        seen[n] = 1;
        for(int i = 0; i < adj[n].size(); i++) {
            if(seen[adj[n][i]]) continue;
            if(!seen[adj[n][i]]) sol(adj[n][i], adj, seen, st);
        }
        st.push(n);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        for(vector<int> &it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> ans;
        
        vector<bool> seen(V, 0);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(!seen[i]) {
                sol(i, adj, seen, st);
            }
        }
        
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

// BFS Approach
class Solution {
  public:
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        for(vector<int> &it : edges) {
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int> ans;
        vector<int> indgree(V, 0);
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < adj[i].size(); j++) {
                indgree[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indgree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            ans.push_back(n);
            for(int i = 0; i < adj[n].size(); i++) {
                indgree[adj[n][i]]--;
                if(indgree[adj[n][i]] == 0) q.push(adj[n][i]);
            }
        }
        return ans;
    }
};
