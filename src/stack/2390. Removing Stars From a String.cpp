class Solution 
{
public:
    string removeStars(string s) 
    {
        stack<char> st;
        for(const auto& c : s)
        {
            if(c == '*')
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution 
{
public:
    string removeStars(string s) 
    {
        string ans = "";
        for(const auto& c : s)
        {
            if(ans.size() > 0 && c == '*')
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(c);
            }
        }

        return ans;
    }
};
