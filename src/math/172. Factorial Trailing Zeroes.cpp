class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        int power = 1;
        while (n / pow(5, power) >= 1)
        {
            ans += n / pow(5, power);
            power++;
        }
        return ans;
    }
};