class Solution
{
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        // Code here
        vector<int> ino(N, 0);
        vector<vector<int>> adj(N);

        for (int i = 0; i < P; i++)
        {
            ino[prerequisites[i].first]++;
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
        }

        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (ino[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            for (int i = 0; i < adj[n].size(); i++)
            {
                ino[adj[n][i]]--;
                if (ino[adj[n][i]] == 0)
                {
                    q.push(adj[n][i]);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (ino[i] != 0)
                return 0;
        }
        return 1;
    }
};