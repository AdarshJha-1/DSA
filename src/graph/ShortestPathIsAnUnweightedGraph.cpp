vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	vector<int> ans;
	vector<int> path(n+1, -1);
	vector<bool> visited(n+1, 0);

	vector<vector<int>> adj(n+1);
	for(auto &e:edges) {
		adj[e.first].push_back(e.second);
		adj[e.second].push_back(e.first);
	}
	
	queue<int> q;
	q.push(s);
	visited[s]=1;
	while(!q.empty()) {
		int node=q.front();
		q.pop();
		
		for(int i=0; i<adj[node].size(); i++) {
			if(!visited[adj[node][i]] && path[adj[node][i]] == -1) {
				visited[adj[node][i]]=1;
				path[adj[node][i]]=node;
				q.push(adj[node][i]);
			}
		}
	}

	int target = t;
	while(target != -1) {
		ans.push_back(target);
		target = path[target];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

