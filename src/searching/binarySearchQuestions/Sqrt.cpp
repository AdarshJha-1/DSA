#include <iostream>
#include <vector>
using namespace std;


int findSquareRoot(int x) {
    if (x < 2) {
            return x;
        }
        int s = 0;
        int e = x;
        int ans = -1;
        while(s <= e) {
            int mid = s + (e - s) / 2;
            if (mid == x/mid) {
                return mid;
            } else if (mid > x/mid) {
                e = mid - 1;
            } else {
                ans = mid;
                s = mid + 1;
            }
        }
        return ans; 
}


int main() {

    int ans = findSquareRoot(100);
    cout << ans << endl;
    return 0;
}

