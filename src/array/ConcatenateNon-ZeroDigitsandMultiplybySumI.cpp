class Solution {
public:
    long long sumAndMultiply(int n) {
        long long temp = 0;
        long long sum = 0;
        while (n) {
            if (n % 10 != 0) {
                sum += n % 10;
                temp = temp * 10 + n % 10;
            }
            n /= 10;
        }
        long long ans = 0;
        while (temp) {
            ans = ans * 10 + temp % 10;
            temp /= 10;
        }
        return ans * sum;
    }
};
