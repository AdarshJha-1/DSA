#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void printArray(vector<int> nums) {
  for (auto it = nums.begin(); it != nums.end(); ++it) {
    std::cout << *it << " ";
  }
}

vector<int> sortArray(vector<int> &nums) {
  for (int i = 1; i < nums.size(); i++) {
    int j = i;
    while (j > 0) {
      if (nums[j] < nums[j - 1]) {
        swap(nums[j], nums[j - 1]);
        j--;
      } else {
        break; // ✅ no need to go further if already in correct position
      }
    }
  }
  return nums;
}

int main() {

  vector<int> nums = {5, 2, 3, 1};
  vector<int> ans = sortArray(nums);
  printArray(nums);
  return 0;
}
