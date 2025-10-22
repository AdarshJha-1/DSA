class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites)
    {
        // code here
        int N = n;
        int P = prerequisites.size();
        vector<int> ino(N, 0);
        vector<vector<int>> adj(N);
        vector<int> ans;
        for (int i = 0; i < P; i++)
        {
            ino[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
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
            ans.push_back(n);
            for (int i = 0; i < adj[n].size(); i++)
            {
                ino[adj[n][i]]--;
                if (ino[adj[n][i]] == 0)
                {
                    q.push(adj[n][i]);
                }
            }
        }
        if (ans.size() != N)
            return {};
        return ans;
    }
};