#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;
    bool ans = 0;
    int i = 0, j = 0;
    while(j < str.size()) {
        if(str[i] != str[j]) {
            if((j - i) >= 7) {
                ans = 1;
                break;
            } else {
                i = j;
            }
        }
        j++;
    }

    if(!ans && j - i >= 7) {
        ans = 1;
    }

    if(ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
