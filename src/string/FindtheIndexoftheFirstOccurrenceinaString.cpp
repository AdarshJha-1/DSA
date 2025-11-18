class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i <= n - m; i++) {
            int f = i, s = 0;
            bool isMatch = true;
            while (s < m) {
                if (haystack[f] == needle[s]) {
                    f++, s++;
                } else {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch)
                return i;
        }
        return -1;
    }
};


class Solution {
public:

    void lsp(string &str, vector<int>& arr) {
        int pre = 0, suf = 1;
        while(suf < arr.size()) {
            if(str[pre] == str[suf]) {
                arr[suf] = pre + 1;
                pre++, suf++;
            } else {
                if(pre == 0) {
                    arr[suf] = 0;
                    suf++;
                } else {
                    pre = arr[pre - 1];
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        vector<int> arr(needle.size(), 0);
        lsp(needle, arr);

        int n = haystack.size(), m = needle.size();
        int f = 0, s = 0;
        while(f < n && s < m) {
            if(haystack[f] == needle[s]) {
                f++, s++;
            } else {
                if(s != 0) {
                    s = arr[s - 1];
                } else {
                    f++;
                }
            }
        }
        if(s == m) return f - s;
    
        return -1;
    }
};
