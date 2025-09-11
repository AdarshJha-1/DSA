class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() == 1 ) return 1;
        string ls = "";
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == ' ' && !ls.size()) continue;
            else if(s[i] != ' ') {
                ls += s[i];
            } else {
                return ls.size();
            }
        }   
        return ls.size();
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        string ls = "";

        for (int i = s.size() - 1; i >= 0; i--) {
            if (!ls.size() && s[i] == ' ') {
                continue;
            } else if (s[i] != ' ') {
                ls += s[i];
            } else if (s[i] == ' ') {
                break;
            }
        }
        return ls.size();
    }
};
