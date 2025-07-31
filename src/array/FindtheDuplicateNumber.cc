#include <iostream>
#include <map>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& nums) {
  map<int, bool> m;
  for(int i = 0; i < nums.size(); i++) {
    int key = nums[i];
    cout << key << endl;
    if(m.find(key) != m.end()) {
      cout << "Present"<< key << endl;
      return key;
    }
    m[nums[i]] = true;
  }
  return -1;
}

int main() {
  vector<int> nums = {3,1,3,4,2};
  cout << findDuplicate(nums);
  return 0;
}
