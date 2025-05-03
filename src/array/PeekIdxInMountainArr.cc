#include <iostream>
#include <vector>

using namespace std;

int peakIndexInMountainArrayBF(vector<int> &arr) {
  int peekIdx = 0;
  for (int i = 1; i < arr.size() - 1; i++) {
    if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
      if (arr[peekIdx] < arr[i]) {
        peekIdx = i;
      }
    }
  }
  return peekIdx;
}

int peakIndexInMountainArray(vector<int> &arr) {
  int start = 1;
  int end = arr.size() - 2;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]) {
      return mid;
    } else if (arr[mid] > arr[mid - 1]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}

int main() {
  vector<int> arr = {0, 10, 5, 2};
  cout << peakIndexInMountainArray(arr);
  return 0;
}
