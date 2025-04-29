#include "iostream"
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

void printAllSubarray(vector<int> nums) {
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      int sum = 0;
      for (int k = i; k <= j; k++) {
        sum += nums[k];
        cout << nums[k] << " ";
      }
      cout << " = " << sum << endl;
    }
  }
}

int maxSubArrayBruteForce(vector<int> &nums) {
  int maxSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      int sum = 0;
      for (int k = i; k <= j; k++) {
        sum += nums[k];
      }
      if (sum > maxSum) {
        maxSum = sum;
      }
    }
  }
  return maxSum;
}

int maxSubArrayBetter(vector<int> &nums) {
  int maxSum = 0;
  for (int i = 0; i < nums.size(); i++) {
    int sum = 0;
    for (int j = i; j < nums.size(); j++) {
      sum += nums[j];
      maxSum = max(sum, maxSum);
    }
  }
  return maxSum;
}

int maxSubArray(vector<int> &nums) {
  int maxSum = INT_MIN;
  int currSum = 0;

  for (int i = 0; i < nums.size(); i++) {
    currSum += nums[i];
    maxSum = max(maxSum, currSum);
    if (currSum < 0) {
      currSum = 0;
    }
  }
  return maxSum;
}

int main() {

  vector<int> nums = {5, 4, -1, 7, 8};

  // printAllSubarray(nums);

  cout << maxSubArrayBruteForce(nums) << endl;
  cout << maxSubArrayBetter(nums) << endl;
  cout << maxSubArray(nums) << endl;
  return 0;
}
