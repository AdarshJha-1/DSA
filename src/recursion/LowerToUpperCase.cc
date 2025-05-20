#include <iostream>

using namespace std;

void toUpperCase(string &str, int i) {
  if (i == str.size()) {
    return;
  }
  str[i] = 'A' + str[i] - 'a';
  return toUpperCase(str, i + 1);
}

int main() {
  string str = "adarsh";
  toUpperCase(str, 0);
  cout << str;
  return 0;
}
