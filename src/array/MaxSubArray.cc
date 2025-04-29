#include "iostream"
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int maxSubArrayBruteForce(vector<int> &nums) {

  int maxSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    int sum = nums[i];
    for (int j = i + 1; j < nums.size(); j++) {
      sum = sum + nums[j];
    }
    max(sum, maxSum);
  }

  return maxSum;
}

int main() {

  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

  cout << maxSubArrayBruteForce(nums);
  return 0;
}
