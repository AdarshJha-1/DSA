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

    bool equationsPossible(vector<string> &equations)
    {
        parent.resize(26);
        rank.resize(26);

        for (int i = 0; i < 26; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        for (const auto &eq : equations)
        {
            if (eq[1] == '=')
            {
                unionDSU(eq[0] - 'a', eq[3] - 'a');
            }
        }

        for (const auto &eq : equations)
        {
            if (eq[1] == '!')
            {
                int x = find(eq[0] - 'a');
                int y = find(eq[3] - 'a');
                if (x == y)
                {
                    return false;
                }
            }
        }

        return true;
    }
};