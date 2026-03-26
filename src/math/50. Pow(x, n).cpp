class Solution
{
public:
    double power(double x, long long n)
    {
        if (n == 0)
        {
            return 1;
        }
        double res = myPow(x, n / 2);
        res *= res;
        if (n % 2 == 1)
        {
            res *= x;
        }
        return res;
    }
    double myPow(double x, int n)
    {
        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
            return power(x, N);
        }
        return power(x, N);
    }
};