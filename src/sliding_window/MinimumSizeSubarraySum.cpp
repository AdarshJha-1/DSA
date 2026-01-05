class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int ans = INT_MAX;
        int sum = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];

            if (sum >= target)
            {
                ans = min(ans, (i - j + 1));
                while (j < i)
                {
                    sum -= nums[j++];
                    if (sum < target)
                    {
                        break;
                    }
                    else
                    {
                        ans = min(ans, (i - j + 1));
                    }
                }
            }
        }
        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};