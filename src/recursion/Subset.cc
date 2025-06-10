#include "iostream"
#include "vector"
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
void sub(vector<vector<int>> &ans, vector<int> &nums, vector<int> &temp, int idx) {
  if(idx == nums.size()) {
    ans.push_back(temp);
    return;
  }
  // no
  sub(ans, nums, temp, idx+1);
  // yes
  temp.push_back(nums[idx]);
  sub(ans, nums, temp, idx+1);
  temp.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> ans;
  vector<int> temp;
  sub(ans, nums, temp, 0);
  return ans;
}

int main() {
  vector<int> nums = {1,2,3};
  vector<vector<int>> ans = subsets(nums);
  print2dArr(ans);
}
