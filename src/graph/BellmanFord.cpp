// User function Template for C++

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        const int MAX_INT = 100000000;
        vector<int> dist(V, MAX_INT);
        dist[src] = 0;
        for(int i = 0; i < V - 1; i++) {
            bool change = 0;
            for(int j = 0; j < edges.size(); j++) {
                int u = edges[j][0], v = edges[j][1], w = edges[j][2];
                if(dist[u] != MAX_INT && dist[u] + w < dist[v]) {
                    change = 1;
                    dist[v] = dist[u] + w;
                }
            }
            if(!change) break;
        }
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            if(dist[u] != MAX_INT && dist[u] + w < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};
