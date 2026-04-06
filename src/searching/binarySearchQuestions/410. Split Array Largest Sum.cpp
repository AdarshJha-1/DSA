class Solution
{
public:
    bool isValid(vector<int> &nums, int m, int k)
    {
        int noOfSubArr = 1;
        int i = 0;
        int sum = 0;
        while (i < nums.size())
        {
            if (nums[i] > m)
            {
                return false;
            }
            else if (sum + nums[i] <= m)
            {
                sum += nums[i];
            }
            else
            {
                sum = nums[i];
                noOfSubArr++;
            }
            i++;
        }

        return noOfSubArr <= k;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int l = 0;
        int r = 0;
        for (const auto &num : nums)
        {
            r += num;
            l = max(l, num);
        }
        if (k == 1)
        {
            return r;
        }

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (isValid(nums, m, k))
            {
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }
};