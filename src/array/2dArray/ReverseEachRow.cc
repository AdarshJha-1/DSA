#include <iostream>
#include <utility>

using namespace std;

void reverseEachRow(int arr[][4], int row, int col) {
  for (int i = 0; i < row; i++) {
    int j = 0;
    int k = col - 1;
    while (j < k) {
      swap(arr[i][j], arr[i][k]);
      j++;
      k--;
    }
  }
}

void printArr(int arr[][4], int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int arr[3][4] = {{2, 3, 4, 5}, {1, 2, 6, 8}, {4, 9, 3, 2}};

  printArr(arr, 3, 4);
  reverseEachRow(arr, 3, 4);

  cout << endl << "Reverse" << endl;
  printArr(arr, 3, 4);
  return 0;
}
