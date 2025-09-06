class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + 1;
            if(sum == 10) {
                digits[i] = 0;
                carry = sum / 10;
            } else {
                digits[i] = sum;
                carry = sum / 10;
                break;
            }
        }

        if(carry) {
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }
};
