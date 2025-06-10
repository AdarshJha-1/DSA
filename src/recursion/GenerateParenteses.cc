#include "iostream"
#include "vector"
#include "string"
#include <vector>

using namespace std;

void print2dArr(const vector<string>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    cout << "{ ";
    for (int j = 0; j < nums[i].size(); j++) {
      cout << nums[i][j];
      if (j < nums[i].size() - 1) cout << ", ";
    }
    cout << " }" << endl;
  }
}
void generateP(int n, vector<string> &ans, string temp, int l, int r) {
  if(r > l) {
    return;
  }
  if(l > n && r > n) {
    ans.push_back(temp);
    return;
  }
  // left
  if(l <= n) {
  temp.push_back('(');
  generateP(n, ans, temp, l + 1, r);
  temp.pop_back();
  }
  // right
  if(r <= n) {
  temp.push_back(')');
  generateP(n, ans, temp, l, r + 1);
  temp.pop_back();
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> ans;
  string temp;
  generateP(n, ans, temp, 1, 1);
  return ans;
}

int main() {
  int n =1;
  vector<string> ans = generateParenthesis(n);

  print2dArr(ans);
}
