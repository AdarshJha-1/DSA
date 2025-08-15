#include "iostream"
#include "vector"
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans(nums1.size(), -1);
    for(int i = 0; i < nums1.size(); i++) {
        for(int j = 0; j < nums2.size(); j++) {
            if(nums2[j] == nums1[i]) {
                for(int k = j; k < nums2.size(); k++) {
                    if(nums2[k] > nums2[j]) {
                        ans[i] = nums2[k];
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    vector<int> ans = nextGreaterElement(nums1, nums2);

    for(auto it : ans) {
        cout << it << " ";
    }
    return 0;
}

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(), -1);
        int n = nums.size();
        for(int i = 0; i < 2 * n; i++) {
            while(!st.empty() && nums[i % n] > nums[st.top()]) {
                ans[st.top()] = nums[i % n];
                st.pop();
            }
            st.push(i % n);
        }
        return ans;
    }
};
