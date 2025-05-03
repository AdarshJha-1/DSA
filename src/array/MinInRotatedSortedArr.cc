#include <iostream>
#include <vector>

using namespace std;

int findMinBF(vector<int> &nums) {
  if (nums.size() == 1) {
    return nums[0];
  }
  if (nums[0] < nums[nums.size() - 1]) {
    return nums[0];
  }
  if (nums[nums.size() - 1] < nums[nums.size() - 2] &&
      nums[nums.size() - 1] < nums[0]) {
    return nums[nums.size() - 1];
  }
  for (int i = 1; i < nums.size() - 1; i++) {
    if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
      return nums[i];
    }
  }
  return -1;
}

int findMin(vector<int> &nums) {
  if (nums.size() == 1)
    return nums[0];
  if (nums[0] < nums[nums.size() - 1])
    return nums[0];
  if (nums[nums.size() - 1] < nums[nums.size() - 2] &&
      nums[nums.size() - 1] < nums[0])
    return nums[nums.size() - 1];

  int start = 1;
  int end = nums.size() - 2;
  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1])
      return nums[mid];
    else if (nums[mid] > nums[mid - 1] && nums[mid] > nums[0])
      start = mid + 1;
    else
      end = mid - 1;
  }
  return -1;
}

int main() {
  vector<int> nums = {5, 1, 2, 3, 4};
  cout << findMin(nums);
  return 0;
}
