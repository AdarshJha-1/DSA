class Solution
{
public:
    int findMin(int n)
    {
        int ans = 0;
        while (n)
        {
            if (n >= 10)
            {
                n -= 10;
            }
            else if (n >= 5)
            {
                n -= 5;
            }
            else if (n >= 2)
            {
                n -= 2;
            }
            else
            {
                n -= 1;
            }
            ans++;
        }

        return ans;
    }
};

class Solution
{
public:
    int findMin(int n)
    {
        int ans = 0;
        for (const auto &c : {10, 5, 2, 1})
        {
            ans += n / c;
            n %= c;
        }
        return ans;
    }
};