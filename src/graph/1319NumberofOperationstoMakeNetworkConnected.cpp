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

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
        {
            return -1;
        }
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        int count = 0;
        for (const auto &c : connections)
        {
            int p_x = find(c[0]);
            int p_y = find(c[1]);

            if (p_x == p_y)
            {
                count++;
            }
            else
            {
                unionDSU(c[0], c[1]);
            }
        }

        int haveExtra = count;
        int requiredCon = 0;
        for (int i = 0; i < n; i++)
        {

            if (parent[i] == i)
            {
                requiredCon++;
            }
        }
        requiredCon--;
        if (haveExtra >= requiredCon)
        {
            return requiredCon;
        }

        return -1;
    }
};