#include <iostream>
using namespace std;

void print(int arr[][4], int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void printWave(int arr[][4], int row, int col) {
  for (int j = 0; j < col; j++) {
    if (j % 2 == 0) {
      for (int i = 0; i < row; i++) {
        cout << arr[i][j] << endl;
      }
    } else {
      for (int i = row - 1; i >= 0; i--) {
        cout << arr[i][j] << endl;
      }
    }
    cout << endl;
  }
  cout << endl;
}

int main() {

  int arr[4][4] = {3, 6, 4, 2, 7, 3, 11, 1, 9, 8, 12, 5, 17, 6, 5, 2};

  print(arr, 4, 4);
  printWave(arr, 4, 4);
  return 0;
}
