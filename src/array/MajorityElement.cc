#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int majorityElementBetter(vector<int> &nums) {
  int ans = 0;
  int hightKey = -1;
  unordered_map<int, int> map;

  for (int i = 0; i < nums.size(); i++) {
    if (map.find(nums[i]) == map.end()) {
      map[nums[i]] = 1;
    } else {
      map[nums[i]] += 1;
    }
  }
  for (auto pair : map) {
    if (pair.second > ans) {
      ans = pair.second;
      hightKey = pair.first;
    }
  }
  return hightKey;
}

int majorityElement(vector<int> &nums) {
  int ele;
  int count = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (count == 0) {
      ele = nums[i];
      count = 1;
    } else if (nums[i] == ele) {
      count++;
    } else {
      count--;
    }
  }

  cout << ele << " " << count << endl;
  int eleMaxOccurence = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == ele) {
      eleMaxOccurence++;
    }
  }

  cout << eleMaxOccurence << endl;
  if (eleMaxOccurence > (nums.size() / 2)) {
    return ele;
  }
  return -1;
}

int main() {

  vector<int> nums = {6, 5, 5};
  cout << majorityElement(nums) << endl;

  return 0;
}
