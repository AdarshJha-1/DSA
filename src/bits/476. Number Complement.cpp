class Solution
{
public:
    int findComplement(int num)
    {
        int len = log2(num) + 1;
        int n = (1u << len) - 1;
        return num ^ n;
    }
};