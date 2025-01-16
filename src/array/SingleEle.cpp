#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    int ans = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        ans ^= nums[i];
    }
    return ans;
}

int main() {
    // vector<int> nums = {2,2,1};
    // vector<int> nums = {4,1,2,1,2};
    vector<int> nums = {66};
    int ans = singleNumber(nums);
    cout << ans << endl;
    return 0;
}