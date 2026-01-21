class Solution
{
public:
    // DFS approach
    bool sol(int n, int p, vector<vector<int>> &adj, vector<bool> &seen)
    {
        seen[n] = 1;
        for (int i = 0; i < adj[n].size(); i++)
        {
            if (p == adj[n][i])
                continue;
            if (seen[adj[n][i]])
                return 1;
            if (sol(adj[n][i], n, adj, seen))
                return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);
        for (auto const &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> seen(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!seen[i] && sol(i, -1, adj, seen))
                return 1;
        }
        return 0;
    }
};

class Solution
{
public:
    // BFS Sol
    bool sol(vector<vector<int>> &adj, vector<bool> &seen, queue<int> &q, vector<int> &parent)
    {
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            seen[n] = 1;
            for (int i = 0; i < adj[n].size(); i++)
            {
                if (adj[n][i] == parent[n])
                    continue;
                if (seen[adj[n][i]])
                    return 1;
                parent[adj[n][i]] = n;
                q.push(adj[n][i]);
            }
        }
        return 0;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);
        for (auto const &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> seen(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!seen[i])
            {
                queue<int> q;
                vector<int> parent(V, -1);
                q.push(i);
                if (sol(adj, seen, q, parent))
                    return 1;
            }
        }
        return 0;
    }
};

class Solution
{
public:
    bool solDFS(vector<vector<int>> &adj, int curr, int prev, vector<bool> &seen)
    {
        seen[curr] = true;
        for (const auto &neg : adj[curr])
        {
            if (neg == prev)
            {
                continue;
            }
            else
            {
                if (seen[neg] == true)
                {
                    return false;
                }
                else
                {
                    if (!solDFS(adj, neg, curr, seen))
                        return false;
                }
            }
        }
        return true;
    }

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // creating a adj-list
        vector<vector<int>> adj(V);
        for (const auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // DFS method
        vector<bool> seen(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!seen[i])
            {
                if (!solDFS(adj, i, -1, seen))
                    return true;
            }
        }

        return false;
    }
};

bool isCycle(int V, vector<vector<int>> &edges)
{
    // creating a adj-list
    vector<vector<int>> adj(V);
    for (const auto &e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> seen(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!seen[i])
        {
            queue<pair<int, int>> q;
            q.push({i, -1});
            seen[i] = true;
            while (!q.empty())
            {
                auto curr = q.front();
                q.pop();
                for (const auto &neg : adj[curr.first])
                {
                    if (neg == curr.second)
                    {
                        continue;
                    }
                    else
                    {
                        if (seen[neg] == true)
                        {
                            return true;
                        }
                        else
                        {
                            q.push({neg, curr.first});
                            seen[neg] = true;
                        }
                    }
                }
            }
        }
    }
    return false;
}