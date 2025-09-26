#include <iostream>
#include <string>

using namespace std;

string toLowerCase(string s) {
    string ans = "";
    for (auto& c : s) {
        if (c >= 'A' && c <= 'Z') {
            ans += c + ('a' - 'A');
        } else {
            ans += c;
        }
    }
    return ans;
}

int main() {
    string s = "Hello";
    cout << toLowerCase(s);
    char c = char('A' + 'a');
    cout << c;
    return 0;
}
