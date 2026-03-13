class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        while (s[i] == ' ')
        {
            i++;
        }
        if (s[i] != '+' && s[i] != '-' && !(s[i] >= '0' && s[i] <= '9'))
        {
            return 0;
        }
        long long ans = 0;
        bool sign = false;
        if (s[i] == '-')
        {
            sign = true;
            i++;
        }
        else if (s[i] == '+')
        {
            sign = false;
            i++;
        }
        if (!(s[i] >= '0' && s[i] <= '9'))
        {
            return 0;
        }

        while (i < s.size())
        {
            if (!(s[i] >= '0' && s[i] <= '9'))
            {
                break;
            }
            ans = ans * 10 + (s[i] - '0');
            i++;
            if (ans > INT_MAX)
            {
                return sign ? INT_MIN : INT_MAX;
            }
        }

        return sign ? -1 * int(ans) : int(ans);
    }
};