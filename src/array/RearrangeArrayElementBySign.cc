#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> nums) {
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

vector<int> rearrangeArray(vector<int> &nums) {
  vector<int> pos;
  vector<int> neg;

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < 0) {
      neg.push_back(nums[i]);
    } else {
      pos.push_back(nums[i]);
    }
  }

  vector<int> ans(nums.size());
  int posIdx = 0;
  int negIdx = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (i % 2 == 0) {
      ans[i] = pos[posIdx];
      posIdx++;
    } else {
      ans[i] = neg[negIdx];
      negIdx++;
    }
  }
  return ans;
}

int main() {
  vector<int> nums = {3, 1, -2, -5, 2, -4};
  printArr(nums);
  vector<int> ans = rearrangeArray(nums);
  printArr(ans);
}
