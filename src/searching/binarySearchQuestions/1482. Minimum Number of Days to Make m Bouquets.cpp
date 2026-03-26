class Solution
{
public:
    bool isValid(vector<int> &bloomDay, int m, int k, int day)
    {
        int f = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= day)
            {
                f++;
                if (f == k)
                {
                    m--;
                    f = 0;
                }
                if (m <= 0)
                {
                    return true;
                }
            }
            else
            {
                f = 0;
            }
        }

        return false;
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        if (1LL * n < 1LL * m * k)
        {
            return -1;
        }

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = INT_MAX;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isValid(bloomDay, m, k, mid))
            {
                r = mid - 1;
                ans = min(ans, mid);
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};