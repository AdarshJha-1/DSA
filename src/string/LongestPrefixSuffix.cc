#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int lPSBF(string str) {
  int len = 0;
  string prefix;
  string suffix;

  int start = 0;
  int end = str.size() - 1;
  while (start != str.size() - 2 && end > 0) {

    prefix += str[start];
    suffix = str[end] + suffix;

    if (prefix == suffix) {
      cout << "catch: " << prefix << " " << suffix << endl;
      int currLen = prefix.size();
      len = max(len, currLen);
    }
    start++;
    end--;
  }

  return len;
}

int lPSBetter(string str) {
  int pre = 0;
  int suf = 1;

  vector<int>lsp(str.size(), 0);

  while (suf < str.size()) {
    if(str[suf] == str[pre]) {
      lsp[suf] = pre + 1;
      pre++;
      suf++;
    } else {
      if(pre == 0) {
        lsp[suf] = 0;
        suf++;
      } else {
        pre = lsp[pre - 1];
      }
    }
  }
  return lsp[lsp.size() - 1];
}

int main() {
  string str = "aabcdaabc";
  cout << lPSBetter(str);
  return 0;
}

    int getLPSLength(string &s) {
        vector<string> prefix, suffix;
        
        string temp = "";
        for(int i = 0; i < s.size() - 1; i++) {
            temp += s[i];
            prefix.push_back(temp);
        }
        
        temp = "";
        for(int i = s.size() - 1; i > 0; i--) {
            temp = s[i] + temp;
            suffix.push_back(temp);
        }
        
        int ans = 0;
        for(int i = 0; i < prefix.size(); i++) {
            if(prefix[i] == suffix[i]) {
                int len = prefix[i].size();
                ans = max(ans, len);
            }
        }
        return ans;
    }
