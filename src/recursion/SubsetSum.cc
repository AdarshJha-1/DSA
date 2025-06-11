#include "iostream"
#include "vector"
#include <vector>

using namespace std;

void subSum(vector<int> &arr, int i, int temp, vector<int> &ans, int target) {
  if(i == arr.size()) {
    ans.push_back(temp);
    if(temp == target){
    cout <<  "YES " << temp << " " << target;
}
    return;
  }
  subSum(arr, i + 1, temp, ans, target);
  temp += arr[i];
  subSum(arr, i + 1, temp, ans, target);
}

vector<int> ansS(vector<int> &arr) {
  vector<int> ans;
  subSum(arr, 0, 0, ans, 12);
  return ans;
}

int main() {
  vector<int> arr = {3,4,5};
  vector<int> ans = ansS(arr);
  for(auto it : ans) {
    cout << it << endl;
  }
  return 0;
}

