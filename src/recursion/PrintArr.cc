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

void printArrRev(vector<int> arr, int i) {
  if (i == arr.size() - 1) {
    cout << arr[i] << " ";
    return;
  }
  printArrRev(arr, i + 1);
  cout << arr[i] << " ";
}
int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  int i = 0;
  printArrRev(arr, i);
}
