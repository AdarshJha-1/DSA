class Solution {
public:

    void getAns(vector<string> &choosen, int idx, string s, vector<string> &ans) {
        if(idx == choosen.size()) {
            ans.push_back(s);
            return;
        }

        for(char c: choosen[idx]) {
            getAns(choosen, idx + 1, s + c, ans);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        string arr[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        vector<string> choosen;
        for(auto &d : digits) {
            int i = (d - '0') - 2;
            choosen.push_back(arr[i]);
        }        
        getAns(choosen, 0, "", ans);
        return ans;

    }
};
