#include <iostream>
#include <vector>

using namespace std;

bool checkIfPangram(string sentence) {
  if (sentence.size() < 25) {
    cout << "HERE" << endl;
    return false;
  }
  vector<int> arr(26, 0);
  for (int i = 0; i < sentence.size(); i++) {
    int idx = sentence[i] - 'a';
    arr[idx] = 1;
  }

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  string sentence = "abcdefghijklmnopqrstuvwxy";

  bool ans = checkIfPangram(sentence);
  if (ans) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
