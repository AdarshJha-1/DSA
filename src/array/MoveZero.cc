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

void moveZeroes(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  int zeroTillIdx = 0;
  for (; zeroTillIdx < nums.size(); zeroTillIdx++) {
    if (nums[zeroTillIdx] != 0) {
      break;
    }
  }
  cout << zeroTillIdx << endl;
  vector<int> temp(nums.size());
  for (int i = zeroTillIdx; i < nums.size(); i++) {
    temp.push_back(nums[i]);
  }

  printArr(temp);
  for (int i = 0; i < nums.size(); i++) {
    nums[i] = temp[i];
  }
}

void moveZeroes1(vector<int> &nums) {
  if (nums.size() < 1) {
    return;
  }
  int i = 0;
  for (int j = 0; j < nums.size(); j++) {
    if (nums[j] == 0) {
      continue;
    }
    nums[i] = nums[j];
    i++;
  }

  for (int k = i; k < nums.size(); k++) {
    nums[k] = 0;
  }
}

int main() {
  vector<int> nums = {0};
  printArr(nums);
  moveZeroes1(nums);
  printArr(nums);
}
