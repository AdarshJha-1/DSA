#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int findMaxConsecutiveOnes(vector<int> &nums) {
  int maxOnes = 0;
  int temp = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 1) {
      temp++;
    } else {
      maxOnes = max(maxOnes, temp);
      temp = 0;
    }
  }
  return max(maxOnes, temp);
}
int main() {
  vector<int> nums = {1, 1, 0, 1, 1, 1};
  vector<int> nums1 = {1, 0, 1, 1, 0, 1};
  int ans = findMaxConsecutiveOnes(nums);
  cout << ans;
  return 0;
}
