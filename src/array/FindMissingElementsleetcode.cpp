class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxEle = *max_element(nums.begin(), nums.end());
        int minEle = *min_element(nums.begin(), nums.end());

        int arr[101];
        for(int i = 0; i < nums.size(); i++) arr[nums[i]]++;
        vector<int> ans;
        for(int i = minEle; i <= maxEle; i++) {
            if(arr[i] == 0) ans.push_back(i);
        }

        return ans;
    }
};
