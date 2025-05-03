#include <iostream>
#include <utility>

using namespace std;

void rotate2TimesClockWise(string &s) {
  char lastChar = s[s.size() - 1];
  int i = s.size() - 1;
  while (i > 0) {
    s[i] = s[i - 1];
    i--;
  }
  s[0] = lastChar;
}

void rotate2TimesAntiClockWise(string &s) {
  char firstChar = s[0];
  int i = 0;
  while (i < s.size()) {
    s[i] = s[i + 1];
    i++;
  }

  s[s.size() - 1] = firstChar;
}

bool isRotated(string &s1, string &s2) {
  string clockwise = s1;
  string antiClockwise = s1;

  int i = 0;
  while (i < 2) {
    rotate2TimesClockWise(clockwise);
    rotate2TimesAntiClockWise(antiClockwise);
    i++;
  }
  cout << s2 << " " << clockwise << endl;
  cout << s2 << " " << antiClockwise << endl;
  if (s2 == clockwise) {
    return true;
  }
  if (s2 == antiClockwise) {
    return true;
  }
  return false;
}

int main() {

  string s1 = "geeksforgeeks";
  string s2 = "geeksgeeksfor";

  bool is = isRotated(s1, s2);
  if (is) {
    cout << "YES";
  }

  return 0;
}
