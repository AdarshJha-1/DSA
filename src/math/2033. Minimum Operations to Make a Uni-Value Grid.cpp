class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> arr;
        for (const auto &r : grid)
        {
            for (const auto &v : r)
            {
                arr.push_back(v);
            }
        }

        sort(arr.begin(), arr.end());

        int median = arr[arr.size() / 2];
        int ans = 0;
        for (const auto &v : arr)
        {
            int diff = abs(median - v);
            if (diff % x == 0)
            {
                ans += diff / x;
            }
            else
            {
                return -1;
            }
        }
        return ans;
    }
};