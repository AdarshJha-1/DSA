#include <algorithm>
#include <exception>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool allUnique(string s) {
  unordered_map<char, bool> map;
  for (int i = 0; i < s.size(); i++) {
    if (map.find(s[i]) != map.end()) {
      return false;
    } else {
      map[s[i]] = true;
    }
  }
  return true;
}

// O(n^3)
int lengthOfLongestSubstringBF(string s) {
  int n = s.size();
  int len = 0;
  // find all sub-string
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      string subString;
      for (int k = i; k <= j; k++) {
        subString += s[k];
      }
      if (allUnique(subString)) {
        int subLeb = subString.size();
        len = max(len, subLeb);
      } else {
        break;
      }
    }
  }
  return len;
}

// O(n^2)
int lengthOfLongestSubstringBetter(string s) {
  int n = s.size();
  int len = 0;

  for (int i = 0; i < n; i++) {
    unordered_set<char> set;
    int currLen = 0;
    for (int j = i; j < n; j++) {
      if (set.find(s[j]) != set.end()) {
        break;
      } else {
        set.insert(s[j]);
        currLen++;
        len = max(len, currLen);
      }
    }
  }
  return len;
}

// O(n)
int lengthOfLongestSubstring(string s) {
  int n = s.size();
  int len = 0;

  int charArray[256] = {0};

  int i = 0;
  for (int j = 0; j < s.size(); j++) {
    if (charArray[int(s[j])] == 0) {
      charArray[int(s[j])] = 1;
      len = max(len, j - i + 1);
    } else {
      while (s[i] != s[j]) {
        charArray[int(s[i])] = 0;
        i++;
      }
      charArray[int(s[i])] = 0;
      i++;
      charArray[int(s[j])] = 1;
    }
  }

  return len;
}
int main() {
  string s = "pwwkew";
  cout << lengthOfLongestSubstring(s);
}
