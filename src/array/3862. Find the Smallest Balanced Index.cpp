class Solution
{
public:
    // not good
    int smallestBalancedIndex(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return -1;
        }

        int n = nums.size();

        // prefix stores sum
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = nums[i] + prefix[i - 1];
        }

        // suffix stores product
        vector<long long> suffix(n, 0);
        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = nums[i] * suffix[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (suffix[i + 1] == 0)
                {
                    return i;
                }
            }

            else if (i == n - 1)
            {
                if (prefix[i - 1] == 1)
                {
                    return i;
                }
            }
            else
            {
                if (prefix[i - 1] == suffix[i + 1])
                {
                    return i;
                }
            }
        }

        return -1;
    }
};