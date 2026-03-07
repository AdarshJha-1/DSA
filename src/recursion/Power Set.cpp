class Solution
{
public:
    void sol(vector<string> &ans, string &s, string &temp, int i, int n)
    {
        if (i >= n)
        {
            if (temp.size())
            {
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(s[i]);
        sol(ans, s, temp, i + 1, n);
        temp.pop_back();
        sol(ans, s, temp, i + 1, n);
    }
    vector<string> AllPossibleStrings(string s)
    {
        vector<string> ans;
        string temp = "";
        sol(ans, s, temp, 0, s.size());
        sort(ans.begin(), ans.end());
        return ans;
    }
};