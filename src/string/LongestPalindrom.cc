#include <iostream>
#include <map>

using namespace std;

int longestPalindrome(string s) {
  map<char, int> map;
  for (int i = 0; i < s.size(); i++) {
    if (map.count(s[i]) > 0) {
      map[s[i]]++;
    } else {
      map[s[i]] = 1;
    }
  }

  int ans = 0;
  for (auto &[key, value] : map) {
    if (value % 2 == 0) {
      ans += value;
    } else if (value % 2 == 1) {
      ans += value - 1;
      map[key] = 1;
    }
  }

  for (auto &[key, value] : map) {
    if (value == 1) {
      ans += 1;
      return ans;
    }
  }

  return ans;
}

int main() {
  string s = "ccccaA";
  cout << longestPalindrome(s);
  return 0;
}
