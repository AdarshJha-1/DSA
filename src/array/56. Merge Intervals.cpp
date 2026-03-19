class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;
        int j = 1;
        while (j < intervals.size())
        {
            if (intervals[i][1] >= intervals[j][0])
            {
                intervals[j][0] = intervals[i][0];
                intervals[j][1] = max(intervals[j][1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
            i++;
            j++;
        }

        ans.push_back(intervals[i]);

        return ans;
    }
};
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int minNow = intervals[0][0];
        int maxNow = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= maxNow)
            {
                maxNow = max(maxNow, intervals[i][1]);
            }
            else
            {
                ans.push_back({minNow, maxNow});
                minNow = intervals[i][0];
                maxNow = intervals[i][1];
            }
        }
        ans.push_back({minNow, maxNow});

        return ans;
    }
};