class Solution
{
public:
    int totalWaviness(int num1, int num2)
    {
        int ans = 0;
        for (int i = num1; i <= num2; i++)
        {
            if (((int)log10(i) + 1) >= 3)
            {
                int count = 0;
                string s = to_string(i);
                for (int i = 1; i < s.size() - 1; i++)
                {
                    if ((s[i] > s[i - 1] && s[i] > s[i + 1]) || (s[i] < s[i - 1] && s[i] < s[i + 1]))
                    {
                        count++;
                    }
                }
                ans += count;
            }
        }
        return ans;
    }
};