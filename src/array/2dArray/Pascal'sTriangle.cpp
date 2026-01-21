class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 1)
            return {{1}};
        if (numRows == 2)
            return {{1}, {1, 1}};
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        ans[1] = {1, 1};

        for (int i = 2; i < numRows; i++)
        {
            vector<int> temp(i + 1, 0);
            temp[0] = 1;
            temp[i] = 1;
            int s = ans[i - 1].size();
            for (int j = 1; j < s; j++)
            {
                temp[j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
            ans[i] = temp;
        }

        return ans;
    }
};