class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        if(relations.size() == 0) return time[time.size() - 1];
        
        vector<vector<int>> adj(n + 1);
        for(auto &r : relations) {
            adj[r[0]].push_back(r[1]);
        }

        vector<int> ind(n + 1, 0);
        for(auto &r : adj) {
            for(auto &c : r) ind[c]++;
        }

        vector<int>prevTime(n + 1, 0);
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(ind[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int c = q.front();
            q.pop();
            for(int i = 0; i < adj[c].size(); i++) {
                ind[adj[c][i]]--;
                if(ind[adj[c][i]] == 0) q.push(adj[c][i]);
                prevTime[adj[c][i]] = max(prevTime[adj[c][i]], prevTime[c] + time[c - 1]);
            }
        }

        for(int i = 1; i <= n; i++) {
            prevTime[i] += time[i - 1];
        }

        return *max_element(prevTime.begin(), prevTime.end());
    }
};
