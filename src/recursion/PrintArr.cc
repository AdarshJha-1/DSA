#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> arr, int i) {
  if (i == arr.size() - 1) {
    cout << arr[i];
    return;
  }
  cout << arr[i] << " ";
  printArr(arr, i + 1);
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  int i = 0;
  printArr(arr, i);
}
