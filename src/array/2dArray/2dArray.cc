#include <iostream>
using namespace std;

void print(int arr[][2], int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {

  int arr[3][2] = {1, 2, 3, 4, 5, 6};

  print(arr, 3, 2);
  return 0;
}
