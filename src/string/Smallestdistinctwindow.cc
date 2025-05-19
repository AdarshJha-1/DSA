#include <algorithm>
#include <climits>
#include <iostream>
#include <set>

using namespace std;

int findSubStringBF(string &str) {
  int len = str.size();
  int n = str.size();
  set<char> uniqueChar;

  for (int i = 0; i < str.size(); i++) {
    uniqueChar.insert(str[i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      string subString;
      for (int k = i; k <= j; k++) {
        subString += str[k];
      }
      set<char> subSet;
      for (int i = 0; i < subString.size(); i++) {
        subSet.insert(subString[i]);
      }

      if (uniqueChar.size() == subSet.size()) {
        int subLen = subString.size();
        len = min(len, subLen);
      }
    }
  }
  return len;
}

int findSubString(string &str) {}
int main() {
  string str = "aaab";
  cout << findSubStringBF(str);
  return 0;
}
