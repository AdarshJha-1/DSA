class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int pivotC = 0;
        vector<int> ans;
        for (const auto &n : nums)
        {
            if (n < pivot)
            {
                ans.push_back(n);
            }
            if (n == pivot)
            {
                pivotC++;
            }
        }

        for (int i = 0; i < pivotC; i++)
        {
            ans.push_back(pivot);
        }

        for (const auto &n : nums)
        {
            if (n > pivot)
            {
                ans.push_back(n);
            }
        }
        return ans;
    }
};