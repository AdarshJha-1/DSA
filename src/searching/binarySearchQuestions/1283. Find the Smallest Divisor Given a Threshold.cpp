class Solution
{
public:
    int isValid(vector<int> &nums, int div, int thres)
    {
        int sum = 0;
        for (const auto &n : nums)
        {
            sum += n % div == 0 ? n / div : (n / div) + 1;
            if (sum > thres)
                return sum;
        }
        return sum;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int divSum = isValid(nums, mid, threshold);
            if (divSum <= threshold)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
};

class Solution
{
public:
    int isValid(vector<int> &nums, int div)
    {
        int sum = 0;
        for (const auto &n : nums)
        {
            sum += n % div == 0 ? n / div : (n / div) + 1;
        }
        return sum;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        int ans = r;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int divSum = isValid(nums, mid);
            if (divSum <= threshold)
            {
                r = mid - 1;
                ans = min(ans, mid);
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }
};