#include "iostream"
#include <algorithm>
#include <vector>

using namespace std;
void printArr(vector<int> nums) {
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

int missingNumberDumbAns(vector<int> &nums) {
  sort(nums.begin(), nums.end());

  for (int i = 0; i <= nums.size(); i++) {
    if (nums[i] != i) {
      return i;
    }
  }

  return nums.size();
}

int missingNumber(vector<int> &nums) {
  int numsSum = 0;
  int nNumsSum = nums.size() * (nums.size() + 1) / 2;

  for (int i = 0; i < nums.size(); i++) {
    numsSum += nums[i];
  }

  cout << numsSum << " " << nNumsSum << endl;
  return nNumsSum - numsSum;
}

int main() {
  vector<int> nums = {0, 1};
  int ans = missingNumberDumbAns(nums);
  cout << ans << endl;

  int ans1 = missingNumber(nums);
  cout << ans1 << endl;
  return 0;
}
