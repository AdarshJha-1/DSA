// optimal one
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> lastV = intervals[0];

        for(int i = 1; i < intervals.size(); i++)
        {
            if(lastV[1] >= intervals[i][0])
            {
                lastV[1] = max(lastV[1], intervals[i][1]);
            }
            else 
            {
                ans.push_back(lastV);
                lastV = intervals[i];
            }
        }

        ans.push_back(lastV);

        return ans;
    }
};

