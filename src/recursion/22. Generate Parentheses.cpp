class Solution
{
public:
    bool isValid(string &s)
    {
        int val = 0;
        for (const auto &c : s)
        {
            if (c == '(')
            {
                val += 1;
            }
            else
            {
                val -= 1;
            }

            if (val < 0)
            {
                return false;
            }
        }

        if (val == 0)
        {
            return true;
        }
        return false;
    }

    void sol(string &s, int n, vector<string> &ans)
    {
        if (s.size() == 2 * n)
        {
            if (isValid(s))
            {
                ans.push_back(s);
            }
            return;
        }
        s.push_back('(');
        sol(s, n, ans);
        s.pop_back();
        s.push_back(')');
        sol(s, n, ans);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string s = "";
        sol(s, n, ans);
        return ans;
    }
};

class Solution
{
public:
    void sol(string &s, int op, int clo, int n, vector<string> &ans)
    {
        if (clo > op)
        {
            return;
        }

        if (s.size() == 2 * n)
        {
            ans.push_back(s);
            return;
        }
        if (op < n)
        {
            s.push_back('(');
            sol(s, op + 1, clo, n, ans);
            s.pop_back();
        }
        if (clo < n)
        {
            s.push_back(')');
            sol(s, op, clo + 1, n, ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string s = "";
        sol(s, 0, 0, n, ans);
        return ans;
    }
};