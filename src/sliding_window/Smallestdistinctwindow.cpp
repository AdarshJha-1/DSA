class Solution
{
public:
    int findSubString(string &s)
    {
        // code here
        vector<bool> chars(26, false);
        int count = 0;
        for (const auto &c : s)
        {
            if (chars[c - 'a'] == false)
            {
                chars[c - 'a'] = true;
                count++;
            }
        }
        vector<int> freq(26, 0);
        int ans = s.size();

        int i = 0;
        int j = 0;
        int n = count;
        while (i < s.size())
        {
            if (freq[s[i] - 'a'] == 0)
            {
                n--;
            }
            freq[s[i] - 'a'] += 1;

            while (n == 0)
            {
                ans = min(ans, i - j + 1);
                freq[s[j] - 'a']--;
                if (freq[s[j] - 'a'] == 0)
                {
                    n++;
                }
                j++;
            }

            i++;
        }

        return ans;
    }
};