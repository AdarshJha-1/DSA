class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        for (auto as : asteroids)
        {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && as < 0)
            {
                if (st.top() == abs(as))
                {
                    destroyed = true;
                    st.pop();
                    break;
                }
                else if (st.top() < abs(as))
                {
                    st.pop();
                }
                else
                {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed)
            {
                st.push(as);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};