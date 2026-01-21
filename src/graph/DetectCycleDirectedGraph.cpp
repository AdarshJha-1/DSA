class Solution
{
public:
    bool sol(int n, vector<vector<int>> &adj, vector<bool> &seen, vector<bool> &path)
    {
        seen[n] = 1;
        path[n] = 1;
        for (int i = 0; i < adj[n].size(); i++)
        {
            if (path[adj[n][i]])
                return 1;
            if (!seen[adj[n][i]] && sol(adj[n][i], adj, seen, path))
                return true;
        }
        path[n] = 0;
        return 0;
    }

    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
        }
        vector<bool> seen(V, 0);
        vector<bool> path(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!seen[i] && sol(i, adj, seen, path))
                return 1;
        }
        return 0;
    }
};

class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<int> ind(V, 0);
        vector<vector<int>> adj(V);
        for (auto e : edges)
        {
            ind[e[1]]++;
            adj[e[0]].push_back(e[1]);
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (ind[i] == 0)
                q.push(i);
        }

        int c = 0;

        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            c++;
            for (int i = 0; i < adj[n].size(); i++)
            {
                ind[adj[n][i]]--;
                if (ind[adj[n][i]] == 0)
                    q.push(adj[n][i]);
            }
        }

        return c != V;
    }
};

// New here

class Solution
{
public:
    bool solDFS(vector<vector<int>> &adj, vector<bool> &seen, vector<bool> &path, int curr)
    {
        seen[curr] = true;
        path[curr] = true;
        for (const auto &neg : adj[curr])
        {
            if (path[neg] == true)
            {
                return false;
            }
            else
            {
                if (!seen[neg])
                {
                    if (!solDFS(adj, seen, path, neg))
                    {
                        return false;
                    }
                }
            }
        }
        path[curr] = false;
        return true;
    }

    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // creating adj-list
        vector<vector<int>> adj(V);
        for (const auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
        }

        // using DFS
        vector<bool> seen(V, false);
        vector<bool> path(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!seen[i])
            {
                if (!solDFS(adj, seen, path, i))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // creating adj-list
        vector<vector<int>> adj(V);
        for (const auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
        }

        // using BFS

        // creating indgree array
        vector<int> ind(V, 0);
        vector<bool> seen(V, false);
        for (const auto &e : edges)
        {
            ind[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (ind[i] == 0)
            {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;
            seen[node] = true;

            for (const auto &neg : adj[node])
            {
                ind[neg]--;
                if (ind[neg] == 0)
                {
                    q.push(neg);
                }
            }
        }

        return count == V ? false : true;
    }
};