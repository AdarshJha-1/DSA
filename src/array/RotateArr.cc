#include "iostream"
#include <vector>

using namespace std;
void printArr(vector<int> nums) {
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
}
void rotateLinearApproach(vector<int> &nums, int k) {
  while (k--) {
    int temp = nums[nums.size() - 1]; // last element
    for (int i = nums.size() - 1; i > 0; i--) {
      nums[i] = nums[i - 1];
    }

    nums[0] = temp;
  }
}

void reverseArrWithGIvenIdx(vector<int> &nums, int start, int end) {
  while (start <= end) {
    swap(nums[start], nums[end]);
    start++;
    end--;
  }
}

void rotateGoodSolution(vector<int> &nums, int k) {
  k = k % nums.size();
  reverseArrWithGIvenIdx(nums, 0, nums.size() - 1); // first whole list
  reverseArrWithGIvenIdx(nums, 0, k - 1);           // for first k - 1 elements
  reverseArrWithGIvenIdx(nums, k,
                         nums.size() - 1); // for second half from k to list end
}
int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  printArr(nums);
  rotateGoodSolution(nums, 3);
  printArr(nums);
  vector<int> nums1 = {-1, -100, 3, 99};
  printArr(nums1);
  rotateGoodSolution(nums1, 2);
  printArr(nums1);
  return 0;
}
