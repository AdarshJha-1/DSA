#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSumNotGood(vector<int> &nums, int target) {
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (nums[i] + nums[j] == target) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

vector<int> twoSumBetter(vector<int> &nums, int target) {
  unordered_map<int, int> map;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    map[nums[i]] = i;
  }

  for (int i = 0; i < n; i++) {
    int remain = target - nums[i];
    if (map.find(remain) != map.end() && map[remain] != i) {
      return {i, map[remain]};
    }
  }
  return {};
}

int main() {
  vector<int> nums = {-1, -2, -3, -4, -5};
  int target = -8;
  vector<int> ans = twoSumBetter(nums, target);
  cout << ans[0] << " & " << ans[1] << endl;

  vector<int> nums2 = {2, 7, 11, 15};
  int target2 = 9;
  vector<int> ans2 = twoSumBetter(nums2, target2);
  cout << ans2[0] << " & " << ans2[1] << endl;

  vector<int> nums3 = {3, 2, 4};
  int target3 = 6;
  vector<int> ans3 = twoSumBetter(nums3, target3);
  cout << ans3[0] << " & " << ans3[1] << endl;

  return 0;
}
