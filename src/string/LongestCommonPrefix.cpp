class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<string, int> m;
        for(string str : strs) {
            string temp = "";
            for(char c : str) {
                temp += c;
                m[temp]++;
            }
        }

        string ans = "";
        int nt = strs.size();
        for(auto it : m) {
            if(it.second == nt) {
                string temp = it.first;
                if(temp.size() > ans.size()) {
                    ans = temp;
                }
            } 

        }
        return ans;
    }
};
