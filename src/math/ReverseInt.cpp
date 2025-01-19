#include <iostream>
#include <climits>



using namespace std;

int reverse(int x) {
    long ans = 0;
    while(x != 0) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    if(ans < INT_MIN || ans > INT_MAX) {
        return 0;
    }
    return int(ans);
}

int main() {
    int x = -123;
    cout << reverse(x) << endl;
    return 0;
}