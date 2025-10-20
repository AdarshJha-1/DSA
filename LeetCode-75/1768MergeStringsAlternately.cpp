class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        // flag = 0 -> word1
        // flag = 1 -> word2
        bool flag = 0; 
        int i = 0, j = 0;
        while(i < word1.size() && j < word2.size()) {
            if(!flag) {
                ans += word1[i++];
                flag = !flag;
            } else {
                ans += word2[j++];
                flag = !flag;
            }
        }
        while(i < word1.size()) ans += word1[i++];
        while(j < word2.size()) ans += word2[j++];

        return ans;
    }
};
