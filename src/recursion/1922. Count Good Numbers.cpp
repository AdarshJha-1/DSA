// TLE
class Solution
{
public:
    int countGoodNumbers(long long n)
    {
        long long ans = 1;
        long long MOD = 1000000007;
        for (long long i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ans *= 5;
            }
            else
            {
                ans *= 4;
            }

            if (ans > INT_MAX)
            {
                ans %= MOD;
            }
        }

        return ans % MOD;
    }
};