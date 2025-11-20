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

class Solution {
  public:
    
    // void sol(vector<int>& arr, int target, int sum, int& ans, int i) {
    //     if(i >= arr.size()) {
    //         if(sum == target) ans++;
    //         return;
    //     }
    //     if(sum > target) return;
    //     sol(arr, target, sum + arr[i], ans, i+1);
    //     sol(arr, target, sum, ans, i+1);
    // }
    
    int sol(vector<int>& arr, int target, int sum, int i) {
        if(i >= arr.size()) {
            if(sum == target) return 1;
            return 0;
        }
        if(sum > target) return 0;
        return sol(arr, target, sum + arr[i], i+1) +  sol(arr, target, sum, i+1);
    }
  
    int perfectSum(vector<int>& arr, int target) {

        // int ans = 0;
        // sol(arr, target, 0, ans, 0);
        // return ans;
        
        return sol(arr, target, 0, 0);
    }
};
