class Solution
{
public:
    string generateValidString(int n)
    {
        string str = "0";
        while (n > 1 && n--)
        {
            int s = str.size() - 1;
            str += '1';
            for (int i = s; i >= 0; i--)
            {
                if (str[i] == '0')
                {
                    str += '1';
                }
                else
                {
                    str += '0';
                }
            }
        }

        return str;
    }

    char findKthBit(int n, int k)
    {
        if (n == 1 && k == 1)
        {
            return '0';
        }
        if (k == 1)
        {
            return '0';
        }
        string str = generateValidString(n);
        return str[k - 1];
    }
};