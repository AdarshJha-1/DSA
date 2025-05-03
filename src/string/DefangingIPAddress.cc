#include <iostream>
using namespace std;

string defangIPaddr(string address) {
  int i = 0;
  string ans;
  while (address[i] != '\0') {
    if (address[i] == '.') {
      ans.push_back('[');
      ans.push_back('.');
      ans.push_back(']');
    } else {
      ans.push_back(address[i]);
    }
    i++;
  }
  return ans;
}

int main() {
  string address = "255.100.50.0";
  string ans = defangIPaddr(address);
  cout << ans << endl;
  return 0;
}
