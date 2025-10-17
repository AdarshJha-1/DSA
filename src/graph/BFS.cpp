class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        vector<bool> visited(adj.size(), 0);
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            if(visited[v] == 0) {
                ans.push_back(v);
                visited[v] = 1;
                for(int i = 0; i < adj[v].size(); i++) {
                    q.push(adj[v][i]);
                }
            }
        }
        
        return ans;
    }
};

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        vector<bool> visited(adj.size(), 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for(int i = 0; i < adj[v].size(); i++) {
                if(visited[adj[v][i]] == 0) {
                   visited[adj[v][i]] = 1;
                   q.push(adj[v][i]);
                }
            }
        }
        
        return ans;
    }
};
