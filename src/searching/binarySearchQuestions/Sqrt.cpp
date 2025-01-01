#include <iostream>
#include <vector>
using namespace std;


int findSquareRoot(int x) {
    int s = 0;
    int e = x;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid > x) {
            e = mid - 1;
        } else {
            s = mid + 1;
            ans = mid;
        }
    }
    return ans;   
}


int main() {

    int ans = findSquareRoot(100);
    cout << ans << endl;
    return 0;
}

