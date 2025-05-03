#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> &arr) {
  for (auto it : arr) {
    cout << it << " ";
  }
  cout << endl;
}

int findKthPositiveBF(vector<int> &arr, int k) {
  int nums = 1;
  int i = 0;
  while (k >= 0) {
    if (arr[i] == nums) {
      i++;
      nums++;
    } else {
      k--;
      nums++;
    }
  }
  return nums - k;
}

int findKthPositiveBF2(vector<int> &arr, int k) {
  int n = arr[arr.size() - 1] + k;
  vector<int> temp(n, 0);
  for (int i = 0; i < arr.size(); i++) {
    temp[arr[i] - 1] = 1;
  }

  int counter = 0;
  int idx = 0;
  while (counter < k) {
    if (temp[idx] == 0) {
      counter++;
    }
    idx++;
  }
  return idx;
}
int main() {
  vector<int> arr = {1, 2, 3, 4};
  int k = 2;
  cout << findKthPositiveBF(arr, k) << endl;
  return 0;
}
