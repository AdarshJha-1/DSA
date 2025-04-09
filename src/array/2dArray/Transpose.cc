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

vector<vector<int>> tranpose(vector<vector<int>> arr, int row, int col) {
  vector<vector<int>> ans(col, vector<int>(row));

  for (int j = 0; j < col; j++) {
    for (int i = 0; i < row; i++) {
      ans[j][i] = arr[i][j];
    }
  }
  return ans;
}
void tranposeNoSpace(vector<vector<int>> &arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      // swap(arr[i][j], arr[j][i]);
      int temp = arr[i][j];
      arr[i][j] = arr[j][i];
      arr[j][i] = temp;
    }
  }
}

int main() {

  vector<vector<int>> arr = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  print(arr, 4, 4);
  // vector<vector<int>> ans = tranpose(arr, 4, 4);
  tranposeNoSpace(arr, 4);
  print(arr, 4, 4);
  return 0;
}
