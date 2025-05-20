#include <iostream>
#include <utility>

using namespace std;

void revStr(string &str, int s, int e) {
  if (s >= e)
    return;
  swap(str[s], str[e]);
  return revStr(str, s + 1, e - 1);
}

int main() {
  string str = "Adarsh";
  revStr(str, 0, str.size() - 1);
  cout << str;
  return 0;
}
