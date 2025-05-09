#include <iostream>
#include <map>

using namespace std;

string sortSentence(string s) {
  map<char, string> map;
  string substring = "";
  for (int i = 0; i < s.size(); i++) {
    if (i == s.size() - 1) {
      substring += s[i];
      char key = substring[substring.size() - 1];
      map[key] = substring.erase(substring.size() - 1, 1);
    } else if (s[i] == ' ') {
      char key = substring[substring.size() - 1];
      map[key] = substring.erase(substring.size() - 1, 1);
      substring = "";
    } else {
      substring += s[i];
    }
  }

  for (auto &[key, pair] : map) {
    cout << key << " : " << pair << endl;
  }
  s = "";
  for (char i = '1'; i <= '9'; i++) {
    if (map.count(i) > 0) {
      s += map[i] + " ";
    }
  }
  s.erase(s.size() - 1, 1);
  return s;
}

int main() {
  string s = "Myself2 Me1 I4 and3";
  cout << sortSentence(s);
  return 0;
}
