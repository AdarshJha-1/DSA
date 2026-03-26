class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int maxE = nums[i];
            int minE = nums[i];

            for (int j = i + 1; j < nums.size(); j++)
            {
                maxE = max(maxE, nums[j]);
                minE = min(minE, nums[j]);

                ans += maxE - minE;
            }
        }

        return ans;
    }
};

class Solution
{
public:
    vector<int> NSEL(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    vector<int> NSER(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    vector<int> NGEL(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {

            while (!st.empty() && nums[st.top()] < nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    vector<int> NGER(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {

            while (!st.empty() && nums[st.top()] <= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    long long subArrayRanges(vector<int> &nums)
    {
        vector<int> nsel = NSEL(nums);
        vector<int> nser = NSER(nums);

        vector<int> ngel = NGEL(nums);
        vector<int> nger = NGER(nums);

        long long minSum = 0;
        long long maxSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            minSum += 1LL * (i - nsel[i]) * (nser[i] - i) * nums[i];
            maxSum += 1LL * (i - ngel[i]) * (nger[i] - i) * nums[i];
        }

        return maxSum - minSum;
    }
};