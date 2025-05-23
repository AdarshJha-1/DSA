#include <iostream>

using namespace std;

int searchEle(int arr[], int x, int n, int i) {
  if (i == n)
    return 0;
  if (arr[i] == x)
    return 1;
  return searchEle(arr, x, n, i + 1);
}

int main() {
  int arr[7] = {2, 4, 7, 3, 11, 8, 12};
  int x = 8;
  cout << searchEle(arr, x, 7, 0);
  return 0;
}
