class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.size() == 1 || num.size() == k)
        {
            return "0";
        }

        stack<char> st;

        int i = 0;
        for (; i < num.size(); i++)
        {
            while (!st.empty() && k > 0 && st.top() > num[i])
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k > 0 && !st.empty())
        {
            st.pop();
            k--;
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int j = 0;
        while (j < ans.size() && ans[j] == '0')
        {
            j++;
        }
        string ansSub = ans.substr(j);
        return !ansSub.size() ? "0" : ansSub;
    }
};