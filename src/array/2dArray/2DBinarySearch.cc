#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> arr, int s, int e, int x) {
  int mid = -1;
  while (s <= e) {
    mid = s + (e - s) / 2;
    cout << arr[mid] << endl;
    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] > x) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  return -1;
}

vector<int> BS2DArray(vector<vector<int>> arr, int x) {

  for (int i = 0; i < arr.size(); i++) {
    if (x >= arr[i][0] && x <= arr[i][arr[i].size() - 1]) {
      cout << "Under" << arr[i][0] << " " << arr[i][arr[i].size() - 1] << endl;
      int ans = binarySearch(arr[i], 0, arr[i].size() - 1, x);
      if (ans == -1) {
        return {-1, -1};
      }
      return {i, ans};
    }
  }
  return {-1, -1};
}

vector<int> BS2DArrayBest(vector<vector<int>> arr, int x) {
  int s = 0;
  int e = (arr[0].size() * arr.size()) - 1;
  int mid = 0;
  while (s <= e) {
    mid = s + (e - s) / 2;
    int i = mid / arr[0].size();
    int j = mid % arr[0].size();

    if (arr[i][j] == x) {
      return {i, j};
    } else if (arr[i][j] > x) {
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  return {-1, -1};
}

int main() {
  vector<vector<int>> arr = {
      {2, 6, 10, 14, 18},
      {20, 24, 27, 29, 38},
      {47, 52, 78, 93, 102},
      {108, 111, 200, 218, 320},
  };
  vector<int> ans = BS2DArrayBest(arr, 200);
  cout << "At index: " << ans[0] << "," << ans[1] << endl;
  return 0;
}
