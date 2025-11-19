class Solution {
  public:
    
    void lpsUtil(string &s, vector<int>&lps) {
        int pre = 0, suf = 1;
        while(suf < s.size()) {
            if(s[suf] == s[pre]) {
                lps[suf] = pre + 1;
                suf++, pre++;
            } else {
                if(pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
    }
  
    int minChar(string &s) {
        string str = s;
        reverse(s.begin(), s.end());
        str += s;
        vector<int> lps(str.size(), 0);
        
        lpsUtil(str, lps);
        if(lps[lps.size() - 1] == str.size() - 1) return 0; 
        return  s.size() - lps[lps.size() - 1];
    }
};

