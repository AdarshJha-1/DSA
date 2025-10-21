class Solution
{
public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            char l = s[i], r = s[j];
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                l += 32;
            }
            if (s[j] >= 'A' && s[j] <= 'Z')
            {
                r += 32;
            }
            if (
                (
                    l == 'a' ||
                    l == 'e' ||
                    l == 'i' ||
                    l == 'o' ||
                    l == 'u') &&
                (r == 'a' ||
                 r == 'e' ||
                 r == 'i' ||
                 r == 'o' ||
                 r == 'u'))
            {
                swap(s[i++], s[j--]);
            }
            else if (
                (
                    l == 'a' ||
                    l == 'e' ||
                    l == 'i' ||
                    l == 'o' ||
                    l == 'u') &&
                (r != 'a' ||
                 r != 'e' ||
                 r != 'i' ||
                 r != 'o' ||
                 r != 'u'))
            {
                j--;
            }
            else if (
                (
                    l != 'a' ||
                    l != 'e' ||
                    l != 'i' ||
                    l != 'o' ||
                    l != 'u') &&
                (r == 'a' ||
                 r == 'e' ||
                 r == 'i' ||
                 r == 'o' ||
                 r == 'u'))
            {
                i++;
            }
            else
            {
                i++, j--;
            }
        }

        return s;
    }
};

class Solution
{
public:
    bool isVowel(char c)
    {
        if (c >= 'A' && c <= 'Z')
            c += 32;
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (isVowel(s[i]) && isVowel(s[j]))
            {
                swap(s[i++], s[j--]);
            }
            else if (!isVowel(s[i]))
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return s;
    }
};