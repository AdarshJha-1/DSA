class Solution
{
public:
    bool sol(vector<vector<int>> &adj, vector<int> &color, int currColor, int node)
    {
        color[node] = currColor;
        for (const auto &nei : adj[node])
        {
            if (color[nei] == color[node])
            {
                return false;
            }
            if (color[nei] == -1)
            {
                int nextColor = 1 - currColor;
                if (!sol(adj, color, nextColor, nei))
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        int currColor = 0;

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1 && !sol(graph, color, currColor, i))
            {
                return false;
            }
        }

        return true;
    }
};

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                queue<int> q;
                q.push(i);
                color[i] = 1;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for (const auto &nei : graph[node])
                    {
                        if (color[node] == color[nei])
                        {
                            return false;
                        }
                        if (color[nei] == -1)
                        {
                            color[nei] = 1 - color[node];
                            q.push(nei);
                        }
                    }
                }
            }
        }

        return true;
    }
};