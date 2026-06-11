class Solution
{
public:
    vector<int> minVI;
    vector<int> maxVI;

    // for max
    void buildMax(vector<int> &nums, int i, int l, int r)
    {
        if (l == r)
        {
            maxVI[i] = l;
            return;
        }

        int m = l + (r - l) / 2;
        buildMax(nums, 2 * i + 1, l, m);
        buildMax(nums, 2 * i + 2, m + 1, r);

        if (nums[maxVI[2 * i + 1]] > nums[maxVI[2 * i + 2]])
        {
            maxVI[i] = maxVI[2 * i + 1];
        }
        else
        {
            maxVI[i] = maxVI[2 * i + 2];
        }
    }

    int queryMax(vector<int> &nums, int rl, int rr, int i, int l, int r)
    {
        if (r < rl || l > rr)
        {
            return -1;
        }
        if (l >= rl && r <= rr)
        {
            return maxVI[i];
        }
        int m = l + (r - l) / 2;
        int i1 = queryMax(nums, rl, rr, 2 * i + 1, l, m);
        int i2 = queryMax(nums, rl, rr, 2 * i + 2, m + 1, r);

        if (i1 == -1)
            return i2;
        if (i2 == -1)
            return i1;

        return nums[i1] > nums[i2] ? i1 : i2;
    }

    // for min
    void buildMin(vector<int> &nums, int i, int l, int r)
    {
        if (l == r)
        {
            minVI[i] = l;
            return;
        }

        int m = l + (r - l) / 2;
        buildMin(nums, 2 * i + 1, l, m);
        buildMin(nums, 2 * i + 2, m + 1, r);

        if (nums[minVI[2 * i + 1]] < nums[minVI[2 * i + 2]])
        {
            minVI[i] = minVI[2 * i + 1];
        }
        else
        {
            minVI[i] = minVI[2 * i + 2];
        }
    }

    int queryMin(vector<int> &nums, int rl, int rr, int i, int l, int r)
    {
        if (r < rl || l > rr)
        {
            return -1;
        }
        if (l >= rl && r <= rr)
        {
            return minVI[i];
        }
        int m = l + (r - l) / 2;
        int i1 = queryMin(nums, rl, rr, 2 * i + 1, l, m);
        int i2 = queryMin(nums, rl, rr, 2 * i + 2, m + 1, r);

        if (i1 == -1)
            return i2;
        if (i2 == -1)
            return i1;

        return nums[i1] < nums[i2] ? i1 : i2;
    }

    long long maxTotalValue(vector<int> &nums, int k)
    {

        int n = nums.size();
        minVI.resize(4 * n, -1);
        maxVI.resize(4 * n, -1);

        priority_queue<array<int, 3>> pq;

        buildMax(nums, 0, 0, n - 1);
        buildMin(nums, 0, 0, n - 1);

        long long ans = 0;
        for (int l = 0; l < n; l++)
        {
            int val = nums[queryMax(nums, l, n - 1, 0, 0, n - 1)] - nums[queryMin(nums, l, n - 1, 0, 0, n - 1)];
            pq.push({val, l, n - 1});
        }

        while (k-- && !pq.empty())
        {
            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;
            if (r - 1 >= l)
            {
                int val1 = nums[queryMax(nums, l, r - 1, 0, 0, n - 1)] - nums[queryMin(nums, l, r - 1, 0, 0, n - 1)];
                pq.push({val1, l, r - 1});
            }
        }

        return ans;
    }
};