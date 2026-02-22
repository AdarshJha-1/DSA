class Solution
{
public:
    string maximumXor(string s, string t)
    {
        int n1 = 0;
        int n0 = 0;

        for (const auto &c : t)
        {
            if (c == '1')
            {
                n1++;
            }
            else
            {
                n0++;
            }
        }

        string ns = "";
        for (const auto &c : s)
        {
            if (c == '1')
            {
                if (n0 > 0)
                {
                    ns += '0';
                    n0--;
                }
                else
                {
                    ns += '1';
                    n1--;
                }
            }
            if (c == '0')
            {
                if (n1 > 0)
                {
                    ns += '1';
                    n1--;
                }
                else
                {
                    ns += '0';
                    n0--;
                }
            }
        }

        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1' && ns[i] == '1')
            {
                ans += '0';
            }
            else if (s[i] == '0' && ns[i] == '0')
            {
                ans += '0';
            }
            else
            {
                ans += '1';
            }
        }

        return ans;
    }
};

class Solution
{
public:
    string maximumXor(string s, string t)
    {
        int n1 = 0;
        int n0 = 0;

        for (const auto &c : t)
        {
            if (c == '1')
            {
                n1++;
            }
            else
            {
                n0++;
            }
        }

        string ans = "";

        for (const auto &c : s)
        {
            if (c == '0')
            {
                if (n1 > 0)
                {
                    ans += '1';
                    n1--;
                }
                else
                {
                    ans += '0';
                    n0--;
                }
            }

            if (c == '1')
            {
                if (n0 > 0)
                {
                    ans += '1';
                    n0--;
                }
                else
                {
                    ans += '0';
                    n1--;
                }
            }
        }

        return ans;
    }
};