#include <iostream>
#include <vector>

using namespace std;

int subarraySumBF(vector<int> &nums, int k) {
  int ans = 0;
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i; j < nums.size(); j++) {
      int sum = 0;
      for (int k = i; k <= j; k++) {
        sum += nums[k];
      }
      if (sum == k)
        ans++;
    }
  }
  return ans;
}

int subarraySumBetter(vector<int> &nums, int k) {
  //  map<int, bool> map;
  for (int i = 0; i < nums.size(); i++) {
  }
}

int main() {
  vector<int> nums = {1, 1, 1};
  int k = 2;
  cout << subarraySumBF(nums, k);
}
