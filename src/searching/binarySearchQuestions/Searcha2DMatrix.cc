#include "iostream"
#include "vector"
#include <vector>

using namespace std;

bool bs(vector<vector<int>>& matrix, int target, int row) {
        int s = 0;
        int e = matrix[row].size() - 1;
        int mid = 0;
        while (s <= e) {
            mid = s + (e - s) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); i++) {
            if (target >= matrix[i][0] &&
                target <= matrix[i][matrix[i].size() - 1]) {
                return bs(matrix, target, i);
            }
        }
        return false;
    }
int main() {
  vector<vector<int>> mat = {{1}, {2}};
  int target = 2;
  cout << searchMatrix(mat, target);
  return 0;
}
