class Solution
{
public:
    bool checkZeroOnes(string s)
    {
        int maxC1 = 0, maxC0 = 0;
        int c1 = 0, c0 = 0;
        for (char c : s)
        {
            if (c == '0')
            {
                c0++;
                maxC0 = max(maxC0, c0);
                c1 = 0;
            }
            if (c == '1')
            {
                c1++;
                maxC1 = max(maxC1, c1);
                c0 = 0;
            }
        }

        return maxC1 > maxC0;
    }
};