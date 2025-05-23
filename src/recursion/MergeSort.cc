#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> arr) {
  for (auto it : arr) {
    cout << it << " ";
  }
  cout << endl;
}

void merge(vector<int> &arr, int start, int mid, int end) {
  vector<int> temp((end - start) + 1);

  int i = 0;
  int left = start;
  int right = mid + 1;
  while (left <= mid && right <= end) {
    if (arr[left] < arr[right]) {
      temp[i] = arr[left];
      i++;
      left++;
    } else {
      temp[i] = arr[right];
      i++;
      right++;
    }
  }
  while (left <= mid) {
    temp[i] = arr[left];
    i++;
    left++;
  }
  while (right <= end) {
    temp[i] = arr[right];
    i++;
    right++;
  }
  for (int j = 0; j < temp.size(); j++) {
    arr[j + start] = temp[j];
  }
}

void mergeSort(vector<int> &arr, int start, int end) {
  if (start == end)
    return;
  int mid = start + (end - start) / 2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid + 1, end);
  merge(arr, start, mid, end);
}

int main() {
  vector<int> arr = {6, 4, 7, 2, 9, 8, 3, 5};
  int start = 0;
  int end = arr.size() - 1;
  printArr(arr);
  mergeSort(arr, start, end);
  printArr(arr);
  return 0;
}
