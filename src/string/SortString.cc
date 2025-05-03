#include <iostream>
#include <vector>

using namespace std;

string sort(string s) {
  vector<int> alpha(26, 0);
  for (int i = 0; i < s.size(); i++) {
    alpha[s[i] - 'a']++;
  }

  s = "";
  for (int i = 0; i < alpha.size(); i++) {
    int idx = alpha[i];
    while (idx--) {
      cout << 'a' + i << endl;
      s += 'a' + i;
    }
  }
  return s;
}

int main() {

  string s = "edcab";
  cout << sort(s);
  return 0;
}
