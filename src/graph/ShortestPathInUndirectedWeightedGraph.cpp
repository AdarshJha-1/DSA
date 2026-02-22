class Solution {
public:
  vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (const auto &e : edges) {
      adj[e[0]].push_back({e[1], e[2]});
      adj[e[1]].push_back({e[0], e[2]});
    }

    vector<int> ans(n + 1, INT_MAX);
    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    ans[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
      const auto [dist, node] = pq.top();
      pq.pop();

      if (dist > ans[node])
        continue;
      for (const auto &[nei, cost] : adj[node]) {
        if (dist + cost < ans[nei]) {
          ans[nei] = dist + cost;
          pq.push({dist + cost, nei});
          parent[nei] = node;
        }
      }
    }

    vector<int> path;
    int node = n;

    if (ans[node] == INT_MAX)
      return {-1};

    while (parent[node] != node) {
      path.push_back(node);
      node = parent[node];
    }
    path.push_back(node);
    reverse(path.begin(), path.end());
    path.insert(path.begin(), ans[n]);
    return path;
  }
};
