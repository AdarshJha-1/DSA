class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while (j < s.size()) {
            int k = 0;
            if (s[j] == ' ') {
                k = j - 1;
                while (i < k) {
                    swap(s[i], s[k]);
                    i++;
                    k--;
                }
                i = j + 1;
                j = j + 1;
            } else {
                j++;
                continue;
            }
        }
        j--;
        while (i < j) {
            swap(s[i++], s[j--]);
        }

        return s;
    }
};
