class Solution
{
public:
    // TLE
    bool isP(string &s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j < s.size(); j++)
            {
                if (isP(s, i, j))
                {
                    string temp = s.substr(i, j - i + 1);
                    cout << temp << endl;
                    if (temp.size() > ans.size())
                    {
                        ans = temp;
                    }
                }
            }
        }

        return ans;
    }
};