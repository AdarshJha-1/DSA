#include <iostream>
#include <string>

using namespace std;

string add(string num1, string num2) {
  int idx1 = num1.size() - 1, idx2 = num2.size() - 1;
  int carry = 0;
  int sum = 0;
  string ans;
  while (idx2 >= 0) {
    sum = num1[idx1] - '0' + num2[idx2] - '0' + carry;
    carry = sum / 10;
    char ch = '0' + sum % 10;
    ans = ch + ans;
    idx1--;
    idx2--;
  }

  while (idx1 >= 0) {
    sum = num1[idx1] - '0' + carry;
    carry = sum / 10;
    char ch = '0' + sum % 10;
    ans = ch + ans;
    idx1--;
  }

  if (carry) {
    char ch = '0' + carry;
    ans = ch + ans;
  }
  return ans;
}

string addStrings(string num1, string num2) {
  string ans;
  if (num1.size() > num2.size()) {
    ans = add(num1, num2);
  } else {
    ans = add(num2, num1);
  }
  return ans;
}

int main() {
  string num1 = "88", num2 = "123";
  cout << addStrings(num1, num2);
  return 0;
}
