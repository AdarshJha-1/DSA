#include <iostream>

using namespace std;

int whichRoman(char r) {
  switch (r) {
  case 'I':
    return 1;
  case 'V':
    return 5;
  case 'X':
    return 10;
  case 'L':
    return 50;
  case 'C':
    return 100;
  case 'D':
    return 500;
  case 'M':
    return 1000;
  default:
    return -1;
  }
  return -1;
}

int romanToInt(string roman) {
  int ans = 0;

  int i = 0;
  while (i < roman.size() - 1) {
    int currNum = whichRoman(roman[i]);
    int nextNum = whichRoman(roman[i + 1]);

    if (nextNum > currNum) {
      ans -= currNum;
    } else {
      ans += currNum;
    }
    i++;
  }

  ans += whichRoman(roman[i]);
  return ans;
}

int main() {
  string roman = "LXX";
  cout << romanToInt(roman);
  return 0;
}
