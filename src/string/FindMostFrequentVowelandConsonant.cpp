class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }

        int maxV = 0, maxConst = 0;
        for(auto &it : m) {
            if( it.first == 'a' ||
                it.first == 'e' || 
                it.first == 'i' ||
                it.first == 'o' ||
                it.first == 'u' 
            ) {
                maxV = max(maxV, it.second);
            } else {
                maxConst = max(maxConst, it.second);
            }
        }

        return maxV + maxConst;
    }
};
