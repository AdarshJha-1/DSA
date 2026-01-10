class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
            return "";

        int total = t.size();
        unordered_map<char, int> m;
        for (const auto &c : t)
            m[c]++;

        int minLen = INT_MAX;
        int ans = -1;
        int i = 0;
        int j = 0;

        while (j < s.size())
        {
            if (m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if (m[s[j]] >= 0)
                {
                    total--;
                }
            }

            while (total == 0 && i <= j)
            {
                if (minLen > (j - i + 1))
                {
                    minLen = j - i + 1;
                    ans = i;
                }
                if (m.find(s[i]) != m.end())
                {
                    m[s[i]]++;
                    if (m[s[i]] > 0)
                    {
                        total++;
                    }
                }
                i++;
            }
            j++;
        }

        if (ans == -1)
            return "";
        return s.substr(ans, minLen);
    }
};

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
            return "";

        int total = t.size();
        vector<int> m(256);
        for (const auto &c : t)
            m[c]++;

        int minLen = INT_MAX;
        int ans = -1;
        int i = 0;
        int j = 0;

        while (j < s.size())
        {
            m[s[j]]--;
            if (m[s[j]] >= 0)
            {
                total--;
            }
            while (total == 0 && i <= j)
            {
                if (minLen > (j - i + 1))
                {
                    minLen = j - i + 1;
                    ans = i;
                }

                m[s[i]]++;
                if (m[s[i]] > 0)
                {
                    total++;
                }
                i++;
            }
            j++;
        }

        if (ans == -1)
            return "";
        return s.substr(ans, minLen);
    }
};