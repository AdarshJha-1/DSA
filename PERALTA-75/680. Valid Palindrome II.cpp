class Solution
{
public:
    bool removeIthChar(string &s, int i)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l <= r)
        {
            if (l == i)
            {
                l++;
            }
            else if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    bool removeJthChar(string &s, int j)
    {
        int l = 0;
        int r = s.size() - 1;
        while (l <= r)
        {
            if (r == j)
            {
                r--;
            }
            else if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        bool ans = true;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                // 2 cases remove ith char or remove jth char we can check for both if removing one of them give valid palindrome
                if (!removeIthChar(s, i) && !removeJthChar(s, j))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            i++;
            j--;
        }

        return true;
    }
};

class Solution
{
public:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
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

    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        bool ans = true;
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                // 2 cases remove ith char or remove jth char we can check for both if removing one of them give valid palindrome
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
            i++;
            j--;
        }

        return true;
    }
};