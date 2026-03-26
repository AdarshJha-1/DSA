class Solution
{
public:
    vector<int> leftSmaller(vector<int> arr)
    {
        stack<int> st;
        vector<int> ans(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                ans[i] = -1;
                st.push(i);
            }
            else
            {
                ans[i] = arr[st.top()];
                st.push(i);
            }
        }

        return ans;
    }
};