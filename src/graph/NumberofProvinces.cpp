// First Approach
class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &seen, int node)
    {
        seen[node] = true;
        for (const auto &neg : adj[node])
        {
            if (!seen[neg])
            {
                dfs(adj, seen, neg);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<bool> seen(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!seen[i])
            {
                count++;
                dfs(adj, seen, i);
            }
        }
        return count;
    }
};

// Second Approach
class Solution
{
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &seen, int node, int n)
    {
        seen[node] = true;
        for (int i = 0; i < n; i++)
        {
            if (adj[node][i] == 1 && !seen[i])
            {
                dfs(adj, seen, i, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int count = 0;
        vector<bool> seen(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!seen[i])
            {
                count++;
                dfs(isConnected, seen, i, n);
            }
        }
        return count;
    }
};

// Using BFS
class Solution
{
public:
    void bfs(vector<vector<int>> &g, vector<bool> &seen, int node, int n)
    {
        queue<int> q;
        q.push(node);
        seen[node] = true;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if (g[curr][i] == 1 && !seen[i])
                {
                    seen[i] = true;
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<bool> seen(n, false);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!seen[i])
            {
                bfs(isConnected, seen, i, n);
                count++;
            }
        }

        return count;
    }
};