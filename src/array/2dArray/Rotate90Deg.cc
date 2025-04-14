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

vector<vector<int>> rotate90(vector<vector<int>> arr, int n) {
  vector<vector<int>> ans(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ans[j][n - 1 - i] = arr[i][j];
    }
  }
  return ans;
}

void transpose(vector<vector<int>> &arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      swap(arr[i][j], arr[j][i]);
    }
  }
}

void rotate90Best(vector<vector<int>> &arr, int n) {
  transpose(arr, n);
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

int main() {

  vector<vector<int>> arr = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  print(arr, 4, 4);
  vector<vector<int>> ans = rotate90(arr, 4);
  print(ans, 4, 4);
  cout << "Best" << endl;
  rotate90Best(arr, 4);
  print(arr, 4, 4);
  return 0;
}
