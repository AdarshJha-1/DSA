#include <iostream>

using namespace std;

int bs(int arr[], int x, int start, int end) {
  if (start > end)
    return -1;
  int mid = start + (end - start) / 2;
  if (arr[mid] == x) {
    return mid;
  } else if (arr[mid] > x) {
    return bs(arr, x, start, mid - 1);
  } else {
    return bs(arr, x, mid + 1, end);
  }
  return -1;
}

int main() {
  int arr[] = {3, 8, 11, 15, 20, 22};
  int N = 6;
  int x = 20;
  cout << bs(arr, x, 0, N - 1);
  return 0;
}
