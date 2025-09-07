#include <iostream>
#include <string>

std::string addBinary(std::string a, std::string b) {
    std::string ans = "";
    char carry = 0;
    int ia = a.size() - 1;
    int ib = b.size() - 1;
    while (ia >= 0 && ib >= 0) {
        if (a[ia] == '0' && b[ib] == '0') {
            if (carry) {
                ans += '1';
            } else {
                ans += '0';
            }
            carry = 0;
        } else if (a[ia] == '1' && b[ib] == '1') {
            if (carry) {
                ans += '1';
            } else {
                ans += '0';
            }
            carry = 1;
        } else {
            if (carry) {
                ans += '0';
                carry = 1;
            } else {
                ans += '1';
                carry = 0;
            }
        }
        ia--, ib--;
    }

    if (ia != -1) {
        while (ia >= 0) {
            if (a[ia] == '1') {
                if (carry) {
                    ans += '0';
                    carry = 1;
                } else {
                    ans += '1';
                    carry = 0;
                }
            } else {
                if (carry) {
                    ans += '1';
                } else {
                    ans += '0';
                }
                carry = 0;
            }
            ia--;
        }
    }

    if (ib != -1) {
        while (ib >= 0) {
            if (b[ib] == '1') {
                if (carry) {
                    ans += '0';
                    carry = 1;
                } else {
                    ans += '1';
                    carry = 0;
                }
            } else {
                if (carry) {
                    ans += '1';
                } else {
                    ans += '0';
                }
                carry = 0;
            }
            ib--;
        }
    }

    if (carry) {
        ans += '1';
    }

    int s = 0, e = ans.size() - 1;
    while (s <= e) {
        std::swap(ans[s], ans[e]);
        s++, e--;
    }

    return ans;
}

int main() {
    std::string a = "11", b = "1";
    std::cout << addBinary(a, b);
    return 0;
}
