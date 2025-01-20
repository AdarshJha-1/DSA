#include <iostream>
#include <vector>

using namespace std;

// Brute force
bool isPossible(vector<int> arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++) {
    int sum1 = 0;
    int sum2 = 0;
        for(int j = i; j >= 0; j--) {
            sum1 += arr[j];
        }
        for(int k = i + 1; k < n; k++) {
            sum2 += arr[k];
        }
        if(sum1 == sum2) {

            return true;
        }
    }
    return false;
}

int main () {
    vector<int> arr = {3,4,-2,5,8,10,-10,8};
    bool ans = isPossible(arr);
    cout << ans << endl;
    return 0;
}