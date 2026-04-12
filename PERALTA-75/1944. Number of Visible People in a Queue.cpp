class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            int c = 0;
            while (!st.empty() && heights[i] > st.top())
            {
                c++;
                st.pop();
            }

            if (!st.empty())
            {

                c++;
            }
            ans[i] = c;
            st.push(heights[i]);
        }
        return ans;
    }
};