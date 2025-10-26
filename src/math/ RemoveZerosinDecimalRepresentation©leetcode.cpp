#include <iostream>
using namespace std;

    long long removeZeros(long long n) {
        if(n <= 9) return n;
        long long ans = 0;
        while(n) {
            if(n % 10 != 0) {
                ans = ans * 10 + n % 10;
            }
            n /= 10;
        }

        string str = to_string(ans);
        int s = 0, e = str.size() -1;
        while(s < e) {
            swap(str[s++], str[e--]);
        }

        ans = 0;
        for(int i = 0; i < str.size(); i++) {
            ans = ans * 10 + (str[i] - '0');
        }

        return ans;
    }

int main() {
 cout <<    removeZeros(908070605040302010);
    return 0;
}
