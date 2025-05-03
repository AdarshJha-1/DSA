#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int target, int start, int end) {
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return -1;
}

int searchBF(vector<int> &nums, int target) {
  if (nums.size() - 1 < 1) {
    if (nums[0] == target) {
      return 0;
    } else {
      return -1;
    }
  }
  if (nums[0] < nums[nums.size() - 1]) {
    return binarySearch(nums, target, 0, nums.size() - 1);
  }

  int pivot = -1;
  for (int i = 1; i < nums.size() - 2; i++) {
    if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
      pivot = i;
    }
  }

  if (target <= nums[pivot] && target >= nums[0]) {
    return binarySearch(nums, target, 0, pivot);
  } else if (target <= nums[nums.size() - 1] && target >= nums[pivot + 1]) {
    return binarySearch(nums, target, pivot + 1, nums.size() - 1);
  } else {
    return -1;
  }
  return -1;
}

int main() {
  vector<int> nums = {3, 1};
  int target = 0;
  cout << searchBF(nums, target) << endl;
  return 0;
}
