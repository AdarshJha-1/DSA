class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long ans = 0;
        int totalNeg = 0;
        int zeroCount = 0;
        int smallestVal = INT_MAX;

        for (const auto &r : matrix)
        {
            for (const auto &c : r)
            {
                if (c == 0)
                {
                    zeroCount++;
                }
                if (c < 0)
                {
                    totalNeg++;
                }
                ans += abs(c);
                smallestVal = min(smallestVal, abs(c));
            }
        }
        if ((totalNeg % 2 == 0) || (zeroCount > 0))
        {
            return ans;
        }
        return ans - smallestVal - smallestVal;
    }
};
