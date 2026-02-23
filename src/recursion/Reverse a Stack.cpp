class Solution
{
public:
    void reverseStack(stack<int> &st)
    {
        stack<int> temp;
        queue<int> q;
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }

        while (!q.empty())
        {
            st.push(q.front());
            q.pop();
        }
    }
};

class Solution
{
public:
    void reverseStack(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }

        stack<int> temp;
        int val = st.top();
        st.pop();
        reverseStack(st);
        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        temp.push(val);
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }
};

class Solution
{
public:
    void insertAtBottom(int n, stack<int> &st)
    {
        if (st.empty())
        {
            st.push(n);
            return;
        }
        int val = st.top();
        st.pop();
        insertAtBottom(n, st);
        st.push(val);
    }

    void reverseStack(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }

        int val = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(val, st);
    }
};