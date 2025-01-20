#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    int given = x;
    if(x < 0) {
        return false;
    }
    long ans = 0;
    while(x != 0) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return given == ans;
}

int main() {
    int x = 12;
    cout << isPalindrome(x) << endl;
    return 0;
}