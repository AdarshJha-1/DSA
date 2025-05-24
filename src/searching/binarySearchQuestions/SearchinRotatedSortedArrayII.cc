#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> &nums, int target) {
  int start = 0;
  int end = nums.size() - 1;

  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (nums[mid] == target) {
      return true;
    } else if (nums[mid] == nums[0] && target < nums[mid]) {
      end = mid - 1;
    } else if (target < nums[mid] && target >= nums[0]) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return false;
}

int main() {
  vector<int> nums = {1, 0, 1, 1, 1};
  int target = 0;
  cout << search(nums, target);
  return 0;
}
