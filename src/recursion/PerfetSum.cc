#include "iostream"
#include "vector"
#include <vector>

using namespace std;


// TLE
void ps(vector<int> &arr, int target, int &count, int i) {
  if(target < 0 || i == arr.size()) {
  if(target == 0) {
    count++;
  }
    return;
  }

  ps(arr, target, count, i + 1);
  ps(arr, target - arr[i], count, i + 1);
}

int pS(vector<int> &arr, int target,  int i) {
  if(i == arr.size()) {
    return target == 0;
  }
  long long ans = pS(arr, target, i + 1);
  ans += + pS(arr, target - arr[i], i + 1);
  return ans % 1000000007;
}

int perfectSum(vector<int>& arr, int target) {
  int count = 0;
  int i = 0;
  // ps(arr, target, count, i);
  return pS(arr, target, i);
}

int main() {
  vector<int> nums = {2,5,6,1};
  
  int target = 8;
  int ans = perfectSum(nums, target);
  cout << ans;
  return 0;
}
