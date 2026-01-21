class Solution
{
public:
    vector<int> LPS(string &str)
    {
        int n = str.size();
        vector<int> lps(n, 0);

        int pre = 0;
        int suf = 1;

        while (suf < n)
        {
            if (str[pre] == str[suf])
            {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            }
            else
            {
                if (pre == 0)
                {
                    lps[suf] = 0;
                    suf++;
                }
                else
                {
                    pre = lps[pre - 1];
                }
            }
        }

        return lps;
    }

    vector<int> search(string &pat, string &txt)
    {
        int n = txt.size();
        int m = pat.size();

        vector<int> lps = LPS(pat);
        vector<int> ans;

        int i = 0;
        int j = 0;

        while (i < n)
        {
            if (j == m)
            {
                ans.push_back(i - j);
                j = lps[j - 1];
            }
            else if (txt[i] == pat[j])
            {
                i++;
                j++;
            }
            else if (j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j - 1];
            }
        }

        if (j == m)
        {
            ans.push_back(i - j);
        }

        return ans;
    }
};