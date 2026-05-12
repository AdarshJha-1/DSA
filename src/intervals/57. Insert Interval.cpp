// first try -> brute force maybe
class Solution 
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> temp = intervals;
        temp.push_back(newInterval);

        sort(temp.begin(), temp.end());

        // now this basic merge intervals problem

        vector<vector<int>> ans;
        vector<int> lastI = temp[0];

        for(int i = 1; i < temp.size(); i++)
        {
            if(lastI[1] >= temp[i][0])
            {
                lastI[1] = max(lastI[1], temp[i][1]);
            }
            else
            {
                ans.push_back(lastI);
                lastI = temp[i];
            }
        } 

        ans.push_back(lastI);
        return ans;
    }
};
