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

class Solution
{
public:
    long long M = 1000000007;
    long long power(int a, long long n)
    {
        if (n == 0)
        {
            return 1;
        }
        long long res = power(a, n / 2);
        res = (res * res) % M;
        if (n % 2 == 1)
        {
            res = (res * a) % M;
        }
        return res;
    }

    int countGoodNumbers(long long n)
    {
        long long evenC = (n + 1) / 2;
        long long oddC = n - evenC;

        long long evenAns = power(5, evenC);
        long long oddAns = power(4, oddC);
        return (evenAns * oddAns) % M;
    }
};