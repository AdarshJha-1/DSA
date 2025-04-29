#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> nums) {
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

void sortColorsBruteForce(vector<int> &nums) {
  // just sort it :)

  sort(nums.begin(), nums.end());
}

void sortColorWithCounter(vector<int> &nums) {
  int count0 = 0;
  int count1 = 0;
  int count2 = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) {
      count0++;
    } else if (nums[i] == 1) {
      count1++;
    } else {
      count2++;
    }
  }

  for (int i = 0; i < count0; i++) {
    nums[i] = 0;
  }
  for (int i = count0; i < count1 + count0; i++) {
    nums[i] = 1;
  }
  for (int i = count1 + count0; i < count2 + count0 + count1; i++) {
    nums[i] = 2;
  }
}

int main() {
  vector<int> nums = {2, 0, 1};
  printArr(nums);
  sortColorWithCounter(nums);
  printArr(nums);
  return 0;
}
