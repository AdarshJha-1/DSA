class Solution {
public:
    int numberOfSubstrings(string s) {
        int a[3] = {0, 0, 0};
        int i = 0, j = 0, ans = 0, n = s.size();
        while (j < n) {
            a[s[j] - 'a']++;
            while(a[0] > 0 && a[1] > 0 && a[2] > 0) {
                ans += n - j;
                a[s[i] - 'a']--;
                i++;
            }
            j++;
        }

        return ans;
    }
};
