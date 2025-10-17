class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int &n : nums) m[n]++;
        for(auto &it : m) {
            if(it.second % 2 != 0) return false;
        }
        return true;
    }
};


class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[501];
        for(int &n : nums) freq[n]++;
        for(int i = 1; i < 501; i++) {
            if(freq[i] % 2 != 0) return 0;
        }
        return 1;
    }
};
