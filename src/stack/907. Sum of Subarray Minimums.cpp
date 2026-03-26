class Solution
{
public:
    vector<int> NSEL(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
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

    vector<int> NSER(vector<int> &arr)
    {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n, n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
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

    int sumSubarrayMins(vector<int> &arr)
    {
        int M = 1e9 + 7;
        long long ans = 0;
        int n = arr.size();
        vector<int> nsel = NSEL(arr);
        vector<int> nser = NSER(arr);
        for (int i = 0; i < n; i++)
        {
            int left = i - nsel[i];
            int right = nser[i] - i;

            long long accu = (1LL * left * right * arr[i]) % M;
            ans = (ans + accu) % M;
        }

        return int(ans);
    }
};