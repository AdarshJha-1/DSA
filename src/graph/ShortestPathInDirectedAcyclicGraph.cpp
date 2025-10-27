// User function Template for C++
    class Solution {
      public:
        void DFS(int n, vector<vector<pair<int,int>>>&adj, stack<int> &st, vector<bool>& visited) {
            visited[n] = 1;
            for(int i = 0; i < adj[n].size(); i++) {
                if(!visited[adj[n][i].first]) {
                    DFS(adj[n][i].first, adj, st, visited);
                }
            }
            st.push(n);
        }
      
        vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
            // code here
            vector<int> ans(V, INT_MAX);
            vector<vector<pair<int, int>>> adj(V);
            
            for(auto &e : edges) {
                adj[e[0]].push_back({e[1], e[2]});
            }
            
            stack<int> st;
            vector<bool> visited(V, 0);
            DFS(0, adj, st, visited);
            
            
            ans[0] = 0;
            while(!st.empty()) {
                int node = st.top();
                st.pop();
                
                for(int i = 0; i < adj[node].size(); i++) {
                    int n = adj[node][i].first, w = adj[node][i].second; 
                    ans[n] = min(ans[n], w + ans[node]);
                }
            }
            
            for(int i = 0; i < V; i++) {
                if(ans[i] == INT_MAX) ans[i] = -1;
            }
            
            return ans;
        }
    };
