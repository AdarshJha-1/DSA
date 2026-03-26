class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[idx] * 2 < nums[i])
                count++;
        }
        return count;
    }
};
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] > nums[j] * 2)
                    count++;
            }
        }
        return count;
    }
};
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if ((long long)nums[i] > nums[j] * 2LL)
                    count++;
            }
        }
        return count;
    }
};

class Solution
{
public:
    int count = 0;

    void merge(vector<int> &nums, int start, int mid, int end)
    {
        vector<int> temp(end - start + 1, 0);
        int i = start;
        int j = mid + 1;
        while (i <= mid)
        {
            while (j <= end && 1LL * nums[i] > 1LL * 2 * nums[j])
            {
                j++;
            }
            count += (j - (mid + 1));
            i++;
        }

        int l = start;
        int r = mid + 1;
        int idx = 0;
        while (l <= mid && r <= end)
        {
            if (nums[l] <= nums[r])
            {
                temp[idx++] = nums[l++];
            }
            else if (nums[r] < nums[l])
            {
                temp[idx++] = nums[r++];
            }
        }

        while (l <= mid)
        {
            temp[idx++] = nums[l++];
        }
        while (r <= end)
        {
            temp[idx++] = nums[r++];
        }

        idx = 0;
        for (int i = start; i <= end; i++)
        {
            nums[i] = temp[idx++];
        }
    }

    void sol(vector<int> &nums, int start, int end)
    {
        if (start >= end)
        {
            return;
        }
        int mid = start + (end - start) / 2;
        sol(nums, start, mid);
        sol(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }

    int reversePairs(vector<int> &nums)
    {
        sol(nums, 0, nums.size() - 1);
        return count;
    }
};