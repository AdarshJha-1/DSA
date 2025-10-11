// Wrong Sol
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) return 0;
        if(ransomNote.size() == 1 && magazine.size() == 1) return ransomNote == magazine;
        string temp = ""; 
        temp += magazine[0];
        for(int i = 1; i < magazine.size(); i++) {
            if(ransomNote == temp) return 1;
            temp += magazine[i];
        }
        return 0;
    }
};
