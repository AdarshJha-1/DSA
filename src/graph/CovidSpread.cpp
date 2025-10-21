// User function Template for C++

class Solution
{
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        int timer = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < hospital.size(); i++)
        {
            for (int j = 0; j < hospital[i].size(); j++)
            {
                if (hospital[i][j] == 2)
                    q.push({i, j});
            }
        }

        while (!q.empty())
        {
            int n = q.size();
            bool isInfected = 0;
            for (int k = 0; k < n; k++)
            {
                auto [i, j] = q.front();
                q.pop();

                // Left
                if (j - 1 >= 0 && hospital[i][j - 1] == 1)
                {
                    isInfected = 1;
                    hospital[i][j - 1] = 2;
                    q.push({i, j - 1});
                }

                // Right
                if (j + 1 < hospital[i].size() && hospital[i][j + 1] == 1)
                {
                    isInfected = 1;
                    hospital[i][j + 1] = 2;
                    q.push({i, j + 1});
                }

                // Up
                if (i - 1 >= 0 && hospital[i - 1][j] == 1)
                {
                    isInfected = 1;
                    hospital[i - 1][j] = 2;
                    q.push({i - 1, j});
                }

                // Down
                if (i + 1 < hospital.size() && hospital[i + 1][j] == 1)
                {
                    isInfected = 1;
                    hospital[i + 1][j] = 2;
                    q.push({i + 1, j});
                }
            }
            if (isInfected)
                timer++;
        }

        for (int i = 0; i < hospital.size(); i++)
        {
            for (int j = 0; j < hospital[i].size(); j++)
            {
                if (hospital[i][j] == 1)
                    return -1;
            }
        }
        return timer;
    }
};
