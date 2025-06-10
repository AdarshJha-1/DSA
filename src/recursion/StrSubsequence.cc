#include "iostream"
#include "vector"
#include <string>
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

void subs(string str, int i, vector<string> &ans, string temp) {
  if(i == str.size()) {
    ans.push_back(temp);
    return;
  }
  
  subs(str, i + 1, ans, temp);
  temp.push_back(str[i]);
  subs(str, i + 1, ans, temp);
  temp.pop_back();
}

vector<string> getAns(string str) {
  vector<string> ans;
  string temp;
  subs(str, 0, ans, temp);
  return  ans;
}

int main() {
  string str = "abc";
  vector<string> ans = getAns(str);
  print2dArr(ans);
}
