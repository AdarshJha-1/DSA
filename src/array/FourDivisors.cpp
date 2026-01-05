class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int sum = 0;

        for (const auto &n : nums)
        {
            int curr_sum = 0;
            int count = 0;
            for (int i = 1; i * i <= n; i++)
            {
                if (n % i == 0)
                {
                    curr_sum += i;
                    count++;

                    if (i != n / i)
                    {
                        curr_sum += (n / i);
                        count++;
                    }
                }
                if (count > 4)
                    break;
            }
            if (count == 4)
            {
                sum += curr_sum;
            }
        }

        return sum;
    }
};