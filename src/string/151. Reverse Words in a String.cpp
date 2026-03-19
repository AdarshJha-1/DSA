class Solution
{
public:
    string reverseWords(string s)
    {
        bool canSpaceBeAdded = 0;
        int i = 0, j = 0;
        while (j < s.size() && s[j] == ' ')
            j++;
        while (j < s.size())
        {
            if (s[j] != ' ')
            {
                canSpaceBeAdded = 1;
                s[i++] = s[j++];
            }
            else if (canSpaceBeAdded)
            {
                s[i++] = ' ';
                canSpaceBeAdded = 0;
                while (j < s.size() && s[j] == ' ')
                    j++;
            }
        }

        if (i > 0 && s[i - 1] == ' ')
            i--;

        s.resize(i);
        reverse(s.begin(), s.end());
        i = 0, j = 0;
        while (j <= s.size())
        {
            if (j == s.size() || s[j] == ' ')
            {
                reverse(s.begin() + i, s.begin() + j);
                i = j + 1;
            }
            j++;
        }
        return s;
    }
};