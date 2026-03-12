class Solution
{
public:
    void sol(vector<vector<int>> &ans, vector<int> &cand, vector<int> &temp, int idx, int target)
    {

        if (target < 0)
        {
            return;
        }
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < cand.size(); i++)
        {
            if (i > idx && cand[i] == cand[i - 1])
            {
                continue;
            }

            if (cand[i] > target)
            {
                break;
            }
            temp.push_back(cand[i]);
            sol(ans, cand, temp, i + 1, target - cand[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        sol(ans, candidates, temp, 0, target);
        return ans;
    }
};