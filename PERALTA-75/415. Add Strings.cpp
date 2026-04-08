class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string sum = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        int carry = 0;
        while (i >= 0 && j >= 0)
        {
            int d1 = num1[i] - '0';
            int d2 = num2[j] - '0';

            int temp = d1 + d2 + carry;
            carry = temp / 10;
            sum += temp % 10 + '0';
            i--;
            j--;
        }
        while (i >= 0)
        {
            int d = num1[i] - '0';
            int temp = d + carry;
            carry = temp / 10;
            sum += temp % 10 + '0';
            i--;
        }

        while (j >= 0)
        {
            int d = num2[j] - '0';
            int temp = d + carry;
            carry = temp / 10;
            sum += temp % 10 + '0';
            j--;
        }

        if (carry != 0)
        {
            sum += carry + '0';
            carry = 0;
        }

        reverse(sum.begin(), sum.end());

        return sum;
    }
};