class Solution
{
public:
    // Function to detect cycle using DSU in an undirected graph.

    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unionDSU(int x, int y)
    {
        int x_p = find(x);
        int y_p = find(y);

        if (x_p == y_p)
        {
            return;
        }
        if (rank[x_p] > rank[y_p])
        {
            parent[y_p] = x_p;
        }
        else if (rank[y_p] > rank[x_p])
        {
            parent[x_p] = y_p;
        }
        else
        {
            parent[y_p] = x_p;
            rank[x_p]++;
        }
    }
    int detectCycle(int V, vector<int> adj[])
    {
        // Code here
        parent.resize(V);
        rank.resize(V);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        for (int u = 0; u < V; u++)
        {
            for (const auto &v : adj[u])
            {
                if (u < v)
                {
                    int p_u = find(u);
                    int p_v = find(v);
                    if (p_u == p_v)
                    {
                        return true;
                    }
                    unionDSU(u, v);
                }
            }
        }

        return false;
    }
};