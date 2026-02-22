class Solution
{
public:
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

    long long countPairs(int n, vector<vector<int>> &edges)
    {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }

        for (const auto &e : edges)
        {
            unionDSU(e[0], e[1]);
        }

        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[find(i)]++;
        }

        long long total = n;
        long long ans = 0;

        for (const auto &it : m)
        {
            ans += (it.second) * (total - it.second);
            total = total - it.second;
        }

        return ans;
    }
};