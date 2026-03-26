class Solution
{
public:
    bool isValid(vector<int> &wei, int d, int cap)
    {
        int cw = 0;
        int dayUsed = 1;
        for (const auto &w : wei)
        {
            if (cw + w <= cap)
            {
                cw += w;
            }
            else
            {
                dayUsed++;
                cw = w;
            }
        }

        return dayUsed <= d;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int totalWeight = 0;
        for (const auto &w : weights)
        {
            totalWeight += w;
        }

        int l = *max_element(weights.begin(), weights.end());
        int r = totalWeight;
        int ans = totalWeight;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isValid(weights, days, mid))
            {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return ans;
    }
};