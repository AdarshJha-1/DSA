#include "iostream"
#include "vector"

using namespace std;

bool ts(vector<int> &arr, int target, int i) {
  if(target == 0) return 1;
  if(i == arr.size() || target < 0) {
    return 0;
  }

  return ts(arr, target, i + 1) || ts(arr, target - arr[i], i + 1);


}

bool ansS(vector<int> &arr, int target) {
  bool ans;
  ans = ts(arr, target, 0);
  return ans;
}

int main() {
  vector<int> arr = {3,6,4,5};
  int target = 12;
  bool ans = ansS(arr, target);
  cout << ans;
  return 0;
}

