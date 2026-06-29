class Solution
{
public:
    using adjL = unordered_map<string, vector<pair<string, double>>>;

    double dfs(adjL &adj, const string &src, const string &dst, unordered_map<string, bool> &seen, unordered_map<string, bool> &charP)
    {
        if (charP[src] && charP[dst] && src == dst)
        {
            return 1.0;
        }
        seen[src] = true;

        for (const auto &[node, val] : adj[src])
        {
            if (!seen[node])
            {
                double res = 0;
                res = dfs(adj, node, dst, seen, charP);
                if (res != -1.0)
                {
                    return res * val;
                }
            }
        }
        seen[src] = false;
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, bool> charP;
        adjL adj;
        int i = 0;
        for (const auto &eq : equations)
        {
            charP[eq[0]] = true;
            charP[eq[1]] = true;

            adj[eq[0]].push_back({eq[1], values[i]});
            adj[eq[1]].push_back({eq[0], (1 / values[i])});
            i++;
        }

        vector<double> ans;
        for (const auto &q : queries)
        {
            unordered_map<string, bool> seen;
            ans.push_back(dfs(adj, q[0], q[1], seen, charP));
        }

        return ans;
    }
};