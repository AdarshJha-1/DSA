#include <iostream>

using namespace std;

bool isVowel(char c) {
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    return 1;
  }
  return 0;
}

int countVowels(string str, int i) {
  if (i == str.size())
    return 0;
  return isVowel(str[i]) + countVowels(str, i + 1);
}

int main() {
  string str = "rohit";
  cout << countVowels(str, 0);
  return 0;
}
