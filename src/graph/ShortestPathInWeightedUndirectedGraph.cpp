class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});

        }
        
        vector<pair<int, int>> dist(n+1);
        for (int i = 1; i <= n; i++) {
            dist[i].first = INT_MAX;
            dist[i].second = i;
        }
        
        vector<bool> seen(n+1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0, 1});
        dist[1] = {0, 1};
        
        while(!pq.empty()) {
            int node = pq.top().second, v = pq.top().first;
            pq.pop();
            

            if(seen[node]) continue; 
            
            seen[node] = 1;
            
            
            for(int i = 0; i < adj[node].size(); i++) {
                int neg = adj[node][i].first, w = adj[node][i].second;
                if(!seen[neg] && v + w < dist[neg].first) {
                    dist[neg] = {v + w, node};
                    pq.push({v + w, neg});
                }
            }
        }
        
        if(dist[n].first == INT_MAX) return {-1};
        
        
        vector<int> path;
        path.push_back(dist[n].first);
        int i = n;
        while(1) {
            path.push_back(i);
            if(i == 1) break;
            i = dist[i].second;
        }
        
        reverse(path.begin() + 1, path.end());
        return path;
    }
};
