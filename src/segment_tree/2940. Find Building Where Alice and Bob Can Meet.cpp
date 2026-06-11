class Solution
{
public:
    void buildST(vector<int> &heights, vector<int> &segT, int i, int l, int r)
    {
        if (l == r)
        {
            segT[i] = l;
            return;
        }
        int m = l + (r - l) / 2;
        buildST(heights, segT, 2 * i + 1, l, m);
        buildST(heights, segT, 2 * i + 2, m + 1, r);
        segT[i] = (heights[segT[2 * i + 1]] > heights[segT[2 * i + 2]]) ? segT[2 * i + 1] : segT[2 * i + 2];
    }

    int query(vector<int> &segT, vector<int> &heights, int i, int l, int r, int start, int end)
    {
        if (r < start || l > end)
        {
            return -1;
        }
        if (l >= start && r <= end)
        {
            return segT[i];
        }
        int m = l + (r - l) / 2;
        int left = query(segT, heights, 2 * i + 1, l, m, start, end);
        int right = query(segT, heights, 2 * i + 2, m + 1, r, start, end);

        if (left == -1)
        {
            return right;
        }
        if (right == -1)
        {
            return left;
        }

        return heights[left] > heights[right] ? left : right;
    }

    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n = heights.size();
        vector<int> segT(4 * n, INT_MAX);
        buildST(heights, segT, 0, 0, n - 1);

        // for(const auto &c : segT)
        // {
        //     cout << c << " ";
        // }
        // cout << endl;

        vector<int> ans;

        for (const auto &q : queries)
        {
            int a = min(q[0], q[1]);
            int b = max(q[0], q[1]);
            if (a == b || heights[b] > heights[a])
            {
                ans.push_back(b);
            }
            else
            {
                int idx = INT_MAX;
                int start = b + 1;
                int end = n - 1;
                while (start <= end)
                {
                    int m = start + (end - start) / 2;
                    int qv = query(segT, heights, 0, 0, n - 1, start, m);
                    // cout << qv << endl;
                    if (heights[qv] > max(heights[q[0]], heights[q[1]]))
                    {

                        end = m - 1;
                        idx = min(idx, qv);
                    }
                    else
                    {
                        start = m + 1;
                    }
                }

                if (idx == INT_MAX)
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(idx);
                }
            }
        }
        return ans;
    }
};