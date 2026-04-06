class Solution
{
public:
    void sol(vector<vector<int>> &ans, vector<int> &temp, int k, int n, int idx, int sum)
    {
        if (temp.size() == k)
        {
            if (sum == n)
            {
                ans.push_back(temp);
            }
            return;
        }
        for (int i = idx; i <= 9; i++)
        {
            if (sum + i <= n)
            {
                temp.push_back(i);
                sol(ans, temp, k, n, i + 1, sum + i);
                temp.pop_back();
            }
            else
            {
                break;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sol(ans, temp, k, n, 1, 0);
        return ans;
    }
};