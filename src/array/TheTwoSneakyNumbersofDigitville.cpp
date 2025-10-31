class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int arr[100] = {0};
        vector<int> ans;
        for(int &n : nums) arr[n]++;
        for(int i = 0; i < 100; i++) {
            if(arr[i] == 2) ans.push_back(i);
        }
        return ans;
    }
};
