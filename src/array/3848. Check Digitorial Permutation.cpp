class Solution
{
public:
    bool isDigitorialPermutation(int n)
    {
        // i know fact till 8 so
        vector<int> fact(10, 0);
        fact[0] = 1;
        fact[1] = 1;
        fact[2] = 2;
        fact[3] = 6;
        fact[4] = 24;
        fact[5] = 120;
        fact[6] = 720;
        fact[7] = 5040;
        fact[8] = 40320;
        fact[9] = 362880;

        int sum = 0;
        int temp = n;
        while (temp)
        {
            int digit = temp % 10;
            sum += fact[digit];
            temp /= 10;
        }

        if (sum == n)
        {
            return true;
        }

        cout << n << " " << sum << " " << log10(n) << " " << log10(sum) << endl;
        if ((int)(log10(n) + 1) != (int)(log10(sum) + 1))
        {
            cout << "HERE" << endl;
            return false;
        }

        vector<int> t1(10, 0);
        temp = n;
        while (temp)
        {
            t1[temp % 10] += 1;
            temp /= 10;
        }

        vector<int> t2(10, 0);
        while (sum)
        {
            t2[sum % 10] += 1;
            sum /= 10;
        }

        for (int i = 0; i < 10; i++)
        {
            if (t1[i] != t2[i])
            {
                return false;
            }
        }

        return true;
    }
};

class Solution
{
public:
    bool isDigitorialPermutation(int n)
    {

        // i know fact till 8 so
        vector<int> fact(10, 0);
        fact[0] = 1;
        fact[1] = 1;
        fact[2] = 2;
        fact[3] = 6;
        fact[4] = 24;
        fact[5] = 120;
        fact[6] = 720;
        fact[7] = 5040;
        fact[8] = 40320;
        fact[9] = 362880;

        int sum = 0;
        int temp = n;
        vector<int> t1(10, 0);
        while (temp)
        {
            int digit = temp % 10;
            sum += fact[digit];
            t1[digit] += 1;
            temp /= 10;
        }

        if (sum == n)
        {
            return true;
        }

        if ((int)(log10(n) + 1) != (int)(log10(sum) + 1))
        {
            return false;
        }

        vector<int> t2(10, 0);
        while (sum)
        {
            t2[sum % 10] += 1;
            sum /= 10;
        }

        for (int i = 0; i < 10; i++)
        {
            if (t1[i] != t2[i])
            {
                return false;
            }
        }

        return true;
    }
};