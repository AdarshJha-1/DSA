// DFS Approach
class Solution
{
public:
    void sol(int n, vector<vector<int>> &adj, vector<bool> &seen, stack<int> &st)
    {
        seen[n] = 1;
        for (int i = 0; i < adj[n].size(); i++)
        {
            if (seen[adj[n][i]])
                continue;
            if (!seen[adj[n][i]])
                sol(adj[n][i], adj, seen, st);
        }
        st.push(n);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);
        for (vector<int> &it : edges)
        {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> ans;

        vector<bool> seen(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!seen[i])
            {
                sol(i, adj, seen, st);
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

// BFS Approach
class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {

        vector<vector<int>> adj(V);
        for (vector<int> &it : edges)
        {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> ans;
        vector<int> indgree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                indgree[adj[i][j]]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indgree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            ans.push_back(n);
            for (int i = 0; i < adj[n].size(); i++)
            {
                indgree[adj[n][i]]--;
                if (indgree[adj[n][i]] == 0)
                    q.push(adj[n][i]);
            }
        }
        return ans;
    }
};

// NEW HERE

class Solution
{
public:
    void topoSortDFS(vector<vector<int>> &adj, vector<int> &ans, vector<bool> &seen, int curr)
    {
        seen[curr] = true;
        for (const auto neg : adj[curr])
        {
            if (!seen[neg])
            {
                topoSortDFS(adj, ans, seen, neg);
            }
        }
        ans.push_back(curr);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {

        // creating adj-list
        vector<vector<int>> adj(V);
        for (const auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
        }

        // using DFS
        vector<int> ans;
        vector<bool> seen(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!seen[i])
            {
                topoSortDFS(adj, ans, seen, i);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {

        // creating adj-list
        vector<vector<int>> adj(V);
        for (const auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
        }

        // using BFS/Kahn's Algo
        vector<int> ans;

        // finding in-degree with the help of given edges array
        vector<int> ind(V, 0);
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

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (const auto &neg : adj[node])
            {
                ind[neg]--;
                if (ind[neg] == 0)
                {
                    q.push(neg);
                }
            }
        }

        return ans;
    }
};