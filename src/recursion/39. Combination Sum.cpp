class Solution 
{
public:
    void sol(vector<vector<int>>& ans, vector<int>& cand, vector<int>& temp, int tar, int idx)
    {
        if(idx == cand.size() || tar < 0)
        {
            return;
        }
        if(tar == 0)
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(cand[idx]);
        sol(ans, cand, temp, tar - cand[idx], idx);
        temp.pop_back();    
        sol(ans, cand, temp, tar, idx + 1);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp;

        sol(ans, candidates, temp, target, 0);

        return ans;
    }
};