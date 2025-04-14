#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void print(vector<vector<int>> arr, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void transpose(vector<vector<int>> &arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      swap(arr[i][j], arr[j][i]);
    }
  }
}

void reverseArr(vector<vector<int>> &arr, int n) {
  for (int i = 0; i < n; i++) {
    int l = 0;
    int r = n - 1;
    while (l < r) {
      swap(arr[l][i], arr[r][i]);
      l++;
      r--;
    }
  }
}

void rotate90(vector<vector<int>> &arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
    }
  }
}

void rotateMatrix(vector<vector<int>> &arr, int n, int deg) {

  int noOfRotation = (deg / 90);
  while (noOfRotation--) {
    transpose(arr, n);
    reverseArr(arr, n);
  }
}
int main() {

  vector<vector<int>> arr = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  vector<vector<int>> arrOdd = {{1, 2, 3, 4, 5},
                                {6, 7, 8, 9, 10},
                                {11, 12, 13, 14, 15},
                                {16, 17, 18, 19, 20},
                                {21, 22, 23, 24, 25}};

  int deg = 90;
  cout << endl << endl;
  cout << "Best" << endl;
  print(arrOdd, 5, 5);
  cout << "-----new---" << endl;
  rotateMatrix(arrOdd, 5, deg);
  print(arrOdd, 5, 5);

  cout << "EVEN" << endl;
  print(arr, 4, 4);
  cout << "Best" << endl;
  rotateMatrix(arr, 4, deg);
  print(arr, 4, 4);
  return 0;
}
