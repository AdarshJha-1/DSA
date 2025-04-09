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

void spiral(int arr[][4], int top, int bottom, int left, int right) {
  while (top <= bottom && left <= right) {
    for (int i = left; i <= right; i++) {
      cout << arr[top][i] << " ";
    }
    top++;
    for (int i = top; i <= bottom; i++) {
      cout << arr[i][right] << " ";
    }
    right--;
    if (top <= bottom) {
      for (int i = right; i >= left; i--) {
        cout << arr[bottom][i] << " ";
      }
      bottom--;
    }
    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        cout << arr[i][left] << " ";
      }
      left++;
    }
  }
}

int main() {

  int arr[5][4] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                   11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

  print(arr, 4, 5);
  spiral(arr, 0, 4, 0, 3);
  return 0;
}
