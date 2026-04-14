class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long ans = 0;

        int currLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                currLen++;
            }
            else
            {
                ans += 1LL * currLen * (currLen + 1) / 2;
                currLen = 0;
            }
        }

        ans += 1LL * currLen * (currLen + 1) / 2;

        return ans;
    }
};