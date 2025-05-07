#include <iostream>
#include <map>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>> &matrix) {
  map<int, vector<int>> map;

  int counter = 1;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (matrix[i][j] == 0) {
        map[counter++] = {i, j};
      }
    }
  }

  for (auto &[key, indexes] : map) {
    int row = indexes[0];
    int col = indexes[1];

    for (int i = 0; i < matrix[row].size(); i++) {
      matrix[row][i] = 0;
    }
    for (int i = 0; i < matrix.size(); i++) {
      matrix[i][col] = 0;
    }
  }
}

void print2dArray(vector<vector<int>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int main() {
  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  print2dArray(matrix);
  setZeroes(matrix);
  print2dArray(matrix);
  return 0;
}
