class Solution
{
public:
    int gcd(int a, int b)
    {
        while (b % a != 0)
        {
            int temp = b % a;
            b = a;
            a = temp;
        }
        return a;
    }
    string gcdOfStrings(string str1, string str2)
    {
        if ((str1 + str2) != (str2 + str1))
            return "";
        int g = gcd(str1.size(), str2.size());
        string str;
        for (int i = 0; i < g; i++)
        {
            str += str1[i];
        }
        return str;
    }
};
