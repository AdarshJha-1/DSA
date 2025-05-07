#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
  int top = 0;
  int down = matrix.size() - 1;
  int left = 0;
  int right = matrix[0].size() - 1;

  vector<int> ans;
  while (left <= right && top <= down) {

    // top
    for (int i = left; i <= right; i++) {
      ans.push_back(matrix[top][i]);
    }
    top++;

    // right
    for (int i = top; i <= down; i++) {
      ans.push_back(matrix[i][right]);
    }
    right--;

    // down
    if (top <= down) {
      for (int i = right; i >= left; i--) {
        ans.push_back(matrix[down][i]);
      }
      down--;
    }

    // left
    if (left <= right) {
      for (int i = down; i >= top; i--) {
        ans.push_back(matrix[i][left]);
      }
      left++;
    }
  }
  return ans;
}

int main() {
  //  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<int> ans = spiralOrder(matrix);
  for (auto it : ans) {
    cout << it << " ";
  }
  cout << endl;
  return 0;
}
