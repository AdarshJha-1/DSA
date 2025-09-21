class Solution {
public:
    string reverseWords(string s) {
        vector<string> strs;
        string ts = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (ts.size()) {
                    strs.push_back(ts);
                    ts = "";
                }
            } else {
                ts += s[i];
            }
        }

        if(ts.size()) {
            strs.push_back(ts);
        }

        s = "";
        for (int i = strs.size() - 1; i >= 1; i--) {
            s += strs[i];
            s += " ";
        }

        s += strs[0];
        return s;
    }
};
