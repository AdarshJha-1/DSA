#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void printArr(vector<vector<int>> &matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void rotate(vector<vector<int>> &matrix) {

  // first i will transpos this matrix
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = i; j < matrix.size(); j++) {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // reverse it
  for (int i = 0; i < matrix.size(); i++) {
    int start = 0;
    int end = matrix[i].size() - 1;
    while (start < end) {
      swap(matrix[i][start], matrix[i][end]);
      start++;
      end--;
    }
  }
}

int main() {
  vector<vector<int>> matrix = {
      {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  printArr(matrix);
  rotate(matrix);
  printArr(matrix);
  return 0;
}
