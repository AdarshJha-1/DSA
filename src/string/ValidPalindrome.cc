class Solution {
public:
    bool isPalindrome(string s) {
        string tempS = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= 65 && s[i] <= 90) {
                tempS += (s[i] + 32);
            } else if(s[i] >= 97 && s[i] <= 122) {
                tempS += s[i];
            }
        }

        int l = 0, r = tempS.size() - 1;
        while(l <= r) {
            if(tempS[l] != tempS[r]) return false;
            l++, r--;
        }

        return true;
    }
};
