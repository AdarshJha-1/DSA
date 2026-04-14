class Solution
{
public:
    /*
        Brute force is like find first smaller i then go to larger then i, j then find last kth ele larger then jth ele if found return true
        else check all not found -> false - > Will give TLE
    */

    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() <= 2)
        {
            return false;
        }
        for (int i = 0; i < nums.size() - 2; i++)
        {
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                if (nums[j] > nums[i])
                {
                    for (int k = j + 1; k < nums.size(); k++)
                    {
                        if (nums[k] > nums[j])
                            return true;
                    }
                }
            }
        }

        return false;
    }
};

// Working
class Solution
{
public:
    bool solV1(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> small(n, -1);
        int smallIdx = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[smallIdx] < nums[i])
            {
                small[i] = smallIdx;
            }
            else
            {
                smallIdx = i;
            }
        }
        vector<int> big(n, -1);
        int bigIdx = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[bigIdx] > nums[i])
            {
                big[i] = bigIdx;
            }
            else
            {
                bigIdx = i;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (small[i] != -1 && big[i] != -1)
                return true;
        }

        return false;
    }

    // this is just f*ing mind game
    bool solV2(vector<int> &nums)
    {
        int a = INT_MAX, b = INT_MAX;
        for (const auto &num : nums)
        {
            if (num <= a)
            {
                a = num;
            }
            else if (num <= b)
            {
                b = num;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    bool increasingTriplet(vector<int> &nums)
    {
        return solV2(nums);
    }
};