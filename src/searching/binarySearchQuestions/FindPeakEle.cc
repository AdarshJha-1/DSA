#include <iostream>
#include <vector>

using namespace std;
int findPeakElement(vector<int> &nums) {
  if (nums.size() == 1)
    return 0;
  if (nums.size() == 2) {
    return nums[0] > nums[1] ? 0 : 1;
  }
  int start = 0;
  int end = nums.size() - 1;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (mid == 0 && nums[mid] > nums[mid + 1]) {
      return 0;
    }
    if (mid == nums.size() - 1 && nums[mid] > nums[mid - 1]) {
      return nums.size() - 1;
    }
    if (mid != 0 && nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
      return mid;
    } else if (nums[mid] > nums[mid - 1]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}
int main() {
  vector<int> nums = {3, 4, 3, 2, 1};
  cout << findPeakElement(nums);
  return 0;
}
