class Solution
{
public:
    vector<int> LPS(string &str)
    {
        int n = str.size();
        vector<int> lps(n, 0);

        int p = 0;
        int s = 1;
        while (s < n)
        {
            if (str[p] == str[s])
            {
                lps[s] = p + 1;
                s++;
                p++;
            }
            else
            {
                if (p == 0)
                {
                    lps[s] = 0;
                    s++;
                }
                else
                {
                    p = lps[p - 1];
                }
            }
        }

        return lps;
    }

    int minChar(string &s)
    {
        int n = s.size();
        string strR = s;
        reverse(strR.begin(), strR.end());
        string str = s + '$' + strR;
        vector<int> lps = LPS(str);
        return n - lps[lps.size() - 1];
    }
};
