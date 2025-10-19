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
