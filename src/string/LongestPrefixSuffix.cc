#include <algorithm>
#include <iostream>
using namespace std;

int lPSBF(string str) {
  int len = 0;
  string prefix;
  string suffix;

  int start = 0;
  int end = str.size() - 1;
  while (start != str.size() - 2 && end > 0) {

    prefix += str[start];
    suffix = str[end] + suffix;

    if (prefix == suffix) {
      cout << "catch: " << prefix << " " << suffix << endl;
      int currLen = prefix.size();
      len = max(len, currLen);
    }
    start++;
    end--;
  }

  return len;
}

int lPSBetter(string str) {
  int pre = 0;
  int suf = 0;

  while (suf < str.size()) {
    if ()
  }
}

int main() {
  string str = "aabcdaabc";
  cout << lPS(str);
  return 0;
}
