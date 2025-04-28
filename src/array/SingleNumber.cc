#include <iostream>
#include <vector>

using namespace std;
int singleNumber(vector<int> &nums) {
  int ans = nums[0];
  for (int i = 1; i < nums.size(); i++) {
    ans ^= nums[i];
  }
  return ans;
}

int main() {
  vector<int> nums = {4, 1, 2, 1, 2};
  int ans = singleNumber(nums);
  cout << ans << endl;
  return 0;
}
