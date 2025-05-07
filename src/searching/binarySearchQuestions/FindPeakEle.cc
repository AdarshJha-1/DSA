#include <iostream>
#include <vector>

using namespace std;
int findPeakElement(vector<int> &nums) {
  int ans = -1;
  int start = 1;
  int end = nums.size() - 2;

  while (start <= end) {
    int mid = strat + (end - start) / 2;
    if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
      ans = mid;
    }
  }
}
int main() {
  vector<int> nums = {1, 2, 3, 1};
  cout << findPeakElement(nums);
}
