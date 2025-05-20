#include <iostream>
#include <vector>

using namespace std;

void printArrRev(vector<int> arr, int i) {
  if (i == 0) {
    cout << arr[i];
    return;
  }
  cout << arr[i] << " ";
  printArrRev(arr, i - 1);
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  int i = arr.size() - 1;
  printArrRev(arr, i);
}
