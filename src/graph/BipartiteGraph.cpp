class Solution
{
public:
    bool isBipartite(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                q.push(i);
            }

            while (!q.empty())
            {
                int n = q.front();
                q.pop();

                for (int i = 0; i < adj[n].size(); i++)
                {
                    if (color[adj[n][i]] == -1)
                    {
                        color[adj[n][i]] = (color[n] + 1) % 2;
                        q.push(adj[n][i]);
                    }
                    else
                    {
                        if (color[adj[n][i]] == color[n])
                            return 0;
                    }
                }
            }
        }
        return 1;
    }
};

class Solution
{
public:
    bool sol(int n, int p, vector<vector<int>> &adj, vector<int> &color)
    {
        for (int i = 0; i < adj[n].size(); i++)
        {
            if (color[adj[n][i]] == -1)
            {
                color[adj[n][i]] = (color[n] + 1) % 2;
                if (!sol(adj[n][i], n, adj, color))
                    return 0;
            }
            else
            {
                if (color[adj[n][i]] == color[n])
                    return 0;
            }
        }
        return 1;
    }

    bool isBipartite(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                if (!sol(i, -1, adj, color))
                    return 0;
            }
        }
        return 1;
    }
};