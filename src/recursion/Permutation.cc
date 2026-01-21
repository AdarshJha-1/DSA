#include "iostream"
#include "vector"
#include <vector>

using namespace std;

void print2dArr(const vector<vector<int>> &nums)
{
  for (int i = 0; i < nums.size(); i++)
  {
    cout << "{ ";
    for (int j = 0; j < nums[i].size(); j++)
    {
      cout << nums[i][j];
      if (j < nums[i].size() - 1)
        cout << ", ";
    }
    cout << " }" << endl;
  }
}

void helper(vector<int> &nums, vector<vector<int>> &ans, vector<bool> &visited, vector<int> &temp)
{
  if (temp.size() == nums.size())
  {
    ans.push_back(temp);
    return;
  }

  for (int i = 0; i < nums.size(); i++)
  {
    if (visited[i] == 0)
    {
      visited[i] = 1;
      temp.push_back(nums[i]);
      helper(nums, ans, visited, temp);
      visited[i] = 0;
      temp.pop_back();
    }
  }
}

vector<vector<int>> permute(vector<int> &nums)
{
  vector<vector<int>> ans;
  vector<int> temp;
  vector<bool> visited(nums.size(), false);
  helper(nums, ans, visited, temp);
  return ans;
}

int main()
{
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ans = permute(nums);
  print2dArr(ans);
  return 0;
}
