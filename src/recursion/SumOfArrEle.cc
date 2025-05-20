#include <iostream>

using namespace std;

int sum(int arr[], int n, int i) {
  int currSum = arr[i];
  if (i == n - 1) {
    return currSum;
  }
  return currSum + sum(arr, n, i + 1);
}

int main() {
  int arr[] = {3, 4, 5, 8, 2};
  int n = 5;
  int i = 0;
  cout << sum(arr, n, i);
}
