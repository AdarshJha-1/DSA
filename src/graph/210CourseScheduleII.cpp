class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> ind(numCourses, 0);
        vector<int> ans;
        for (const auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            ind[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
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
            for (const auto &nei : adj[node])
            {
                ind[nei]--;
                if (ind[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }

        if (ans.size() == numCourses)
        {
            return ans;
        }
        return {};
    }
};

class Solution
{
public:
    bool dfs(vector<vector<int>> &adj, vector<bool> &seen, vector<bool> &inPath, stack<int> &st, int node)
    {
        seen[node] = true;
        inPath[node] = true;

        for (const auto &nei : adj[node])
        {
            if (inPath[nei])
            {
                return true;
            }
            if (!seen[nei] && dfs(adj, seen, inPath, st, nei))
            {
                return true;
            }
        }
        st.push(node);
        inPath[node] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (const auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> seen(numCourses, false);
        vector<bool> inPath(numCourses, false);
        stack<int> st;
        for (int i = 0; i < numCourses; i++)
        {
            if (!seen[i] && dfs(adj, seen, inPath, st, i))
            {
                return {};
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

class Solution
{
public:
    bool dfs(vector<vector<int>> &adj, vector<bool> &seen, vector<bool> &inPath, int node, vector<int> &ans, int &idx)
    {
        seen[node] = true;
        inPath[node] = true;

        for (const auto &nei : adj[node])
        {
            if (inPath[nei])
            {
                return true;
            }
            if (!seen[nei] && dfs(adj, seen, inPath, nei, ans, idx))
            {
                return true;
            }
        }
        ans[idx--] = node;
        inPath[node] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (const auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> seen(numCourses, false);
        vector<bool> inPath(numCourses, false);
        vector<int> ans(numCourses);
        int idx = numCourses - 1;
        for (int i = 0; i < numCourses; i++)
        {
            if (!seen[i] && dfs(adj, seen, inPath, i, ans, idx))
            {
                return {};
            }
        }
        return ans;
    }
};