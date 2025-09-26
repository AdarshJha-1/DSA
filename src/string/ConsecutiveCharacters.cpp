class Solution {
public:
    int maxPower(string s) {
        if(s.size() == 1) return 1;
        int maxC = 0;
        int i = 0, j = 1;
        while(j <= s.size()) {
            if(s[i] == s[j]) {
                j++;
            } else {
                maxC = max(maxC, (j - i));
                i = j;
                j++;
            }
        }

        return maxC;
    }
};
