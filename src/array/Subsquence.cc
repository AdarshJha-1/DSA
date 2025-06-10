#include <iostream>
#include <vector>

using namespace std;

void print2dArr(const vector<vector<int>>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << "{ ";
        for (int j = 0; j < nums[i].size(); j++) {
            cout << nums[i][j];
            if (j < nums[i].size() - 1) cout << ", ";
        }
        cout << " }" << endl;
    }
}
vector<vector<int>> subsq(vector<int> nums) {
  vector<vector<int>> ans;
  if(nums.size() == 1) {
   ans.push_back({}); 
   ans.push_back(nums);
    return ans;
  }
  if(nums.size() == 2) {
   ans.push_back({}); 
   ans.push_back({nums[0]}); 
   ans.push_back({nums[1]}); 
   ans.push_back(nums); 
    return ans;
  }
  ans.push_back({});
  for(int i = 0; i < nums.size(); i++) {
    vector<int> temp;
    for(int j= i; j < nums.size(); j++) {
      if(i == j) {
      temp.push_back(nums[i]);
      } else {
        temp.push_back(nums[i]);
        temp.push_back(nums[j]);
      }
    ans.push_back(temp);
    temp = {};
    }
  }
  ans.push_back(nums);
  return ans;
}

int main() {
  vector<int> nums = {1, 2};
  vector<vector<int>> ans = subsq(nums);
  print2dArr(ans);
  return 0;
}
