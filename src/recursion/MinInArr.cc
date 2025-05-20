#include <iostream>

using namespace std;

int minInArr(int arr[], int n, int i) {
  if (i == n - 1)
    return arr[i];
  return min(arr[i], minInArr(arr, n, i + 1));
}

int main() {
  int arr[] = {7, 2, 4, 6};
  int n = 4;
  int i = 0;
  cout << minInArr(arr, n, i);
  return 0;
}
