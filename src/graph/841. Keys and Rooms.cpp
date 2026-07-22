class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();

        queue<int> q;
        vector<bool> seen(n, false);

        q.push(0);
        seen[0] = true;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (const auto &nei : rooms[curr])
            {
                if (curr != nei && !seen[nei])
                {
                    seen[nei] = true;
                    q.push(nei);
                }
            }
        }

        for (const auto &v : seen)
        {
            if (!v)
            {
                return false;
            }
        }

        return true;
    }
};