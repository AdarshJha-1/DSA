#include "iostream"
#include "string"

using namespace std;

bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        string ss = "";

        for(int i = 0; i < s.size(); i++) {
            if(s[i] > 122 || s[i] < 97) {
                continue;
            } else if(s[i] >= 65 && s[i] <= 90) {
                ss += s[i] + 32;
      cout << s[i] << " " << s[i]  +32;
            } else { 
                ss += s[i];
            }

        }

        while(l <= r) {
            if(ss[l] != ss[r]) return false;
            l++;
            r--;
        }

  return true;
}

int main() {
  string s = "A man, a plan, a canal: Panama";
  cout << isPalindrome(s);
  return 0;
}
