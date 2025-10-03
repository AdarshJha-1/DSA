#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>arr;
        for(int i = 0; i < n; i++) {
            int ele;
            cin >> ele;
            arr.push_back(ele);
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 1; i < n; i += 2) {
            int diff = arr[i] - arr[i - 1];
            ans = max(ans, diff);
        }
        cout << ans << "\n";
    }
    return 0;
}
