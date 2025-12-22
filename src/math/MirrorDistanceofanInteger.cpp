class Solution
{
public:
    int mirrorDistance(int n)
    {
        int rn = 0;
        int ans = n;
        while (n)
        {
            rn = rn * 10 + (n % 10);
            n /= 10;
        }

        return abs(ans - rn);
    }
};