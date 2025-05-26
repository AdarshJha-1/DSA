#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &nums, int s, int e) {
  if (s >= e)
    return;
  int pivot = nums[e];
  vector<int> less;
  vector<int> more;

  bool isSorted = true;
  for (int i = s; i < e; i++) {
    if (nums[i] <= pivot) {
      less.push_back(nums[i]);
    } else {
      isSorted = false;
      more.push_back(nums[i]);
    }
  }
  if (isSorted) {
    return;
  }

  if (less.size() == 0) {
    nums[e - more.size()] = pivot;
  } else {
    nums[less.size() + s] = pivot;
  }

  for (int i = s; i < less.size(); i++) {
    nums[i] = less[i];
  }
  int j = e - more.size() + 1;
  for (int i = j; i <= e; i++) {
    nums[i] = more[i - j];
  }
  quickSort(nums, s, less.size() - 1);
  quickSort(nums, j, e);
  cout << "time" << endl;
}

void printArr(vector<int> arr) {
  for (auto it : arr) {
    cout << it << " ";
  }
  cout << endl;
}

int main() {
  vector<int> nums = {5, 2, 3, 1};
  printArr(nums);
  quickSort(nums, 0, nums.size() - 1);
  printArr(nums);
  return 0;
}
