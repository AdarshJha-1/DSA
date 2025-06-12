#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int> &arr, int target, int i) {
  if(target < 0) return 0;
  if(i == arr.size()) {
    return target == 0;
  }
  
  return helper(arr, target, i + 1)+ helper(arr, target - arr[i], i); 
}

int ans(vector<int> &arr, int target) {
return   helper(arr, target, 0);
}

int main() {
  vector<int> arr = {2,3,4};
  int target = 6;
  int ways = ans(arr, target);
  cout << ways;
}
