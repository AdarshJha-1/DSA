#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
  map<int, int> m;
  vector<int> ans;
  for(int i = 0; i < nums.size(); i++) {
    m[nums[i]]++;
  }

  int n = nums.size();
  for(const auto& pair : m) {
    if(pair.second > (n / 3)) {
      ans.push_back(pair.first);
    }
  }
  return ans;
}

int main() {
  vector<int> nums = {3,2,3};
  vector<int> ans = majorityElement(nums);

  for(auto it: ans) {
    cout << it << endl;
  }
  return 0;
}
