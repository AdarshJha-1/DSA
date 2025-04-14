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

void rotate180Best(vector<vector<int>> &arr, int n) {
  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; i++) {
      for (int j = 0; j < n; j++) {
        swap(arr[i][j], arr[n - 1 - i][n - 1 - j]);
      }
    }
  } else {
    for (int i = 0; i < (n - 1) / 2; i++) {
      for (int j = 0; j < n; j++) {
        swap(arr[i][j], arr[n - 1 - i][n - 1 - j]);
      }
    }

    int l = 0;
    int r = n - 1;
    int ind = (n - 1) / 2;
    while (l < r) {
      swap(arr[ind][l], arr[ind][r]);
      l++;
      r--;
    }
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
      swap(arr[i][l], arr[i][r]);
      l++;
      r--;
    }
  }
}

void rotate180BestV1(vector<vector<int>> &arr, int n, int deg) {

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

  //  cout << " My Way " << endl;
  //  print(arrOdd, 5, 5);
  //  cout << "-----------" << endl;
  //  rotate180Best(arrOdd, 5);
  //  print(arrOdd, 5, 5);
  //
  //  cout << "EVEN" << endl;
  //  print(arr, 4, 4);
  //  cout << "-----------" << endl;
  //  rotate180Best(arr, 4);
  //  print(arr, 4, 4);

  cout << endl << endl;
  cout << "Best" << endl;
  print(arrOdd, 5, 5);
  cout << "-----new---" << endl;
  rotate180BestV1(arrOdd, 5, 180);
  print(arrOdd, 5, 5);

  cout << "EVEN" << endl;
  print(arr, 4, 4);
  cout << "Best" << endl;
  rotate180BestV1(arr, 4, 180);
  print(arr, 4, 4);
  return 0;
}
