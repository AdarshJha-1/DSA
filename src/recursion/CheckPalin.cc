#include <iostream>

using namespace std;

int isPalindrome(string str, int s, int e) {
  if (s >= e)
    return 1;
  if (str[s] != str[e])
    return 0;
  return isPalindrome(str, s + 1, e - 1);
}

int main() {
  string str = "nam0n";
  cout << isPalindrome(str, 0, str.size() - 1);
  return 0;
}
