#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max(vector<int> arr) {
    int maxEle = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > maxEle) {
            maxEle = arr[i];
        }
    }
    return maxEle;
}
int min(vector<int> arr) {
    int minEle = INT_MAX;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < minEle) {
            minEle = arr[i];
        }
    }
    return minEle;
}

// if sorted
int aggressiveCows(vector<int> arr, int k) {
    int start = 1;
    int end = max(arr) - min(arr);
    int mid = 0;
    int ans = 0;
    while(start <= end) {
        mid = start + (end - start) / 2;
        if(mid * k > max(arr)) {
            end = mid - 1;
        } else {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}

int main() {

    // vector<int> arr = {1,2,4,8,9};
    // vector<int> arr = {2,3, 7,9, 12};
    // vector<int> arr = {2, 12, 11, 3, 26, 7};
    vector<int> arr = {10, 1, 2, 7, 5};
    int k = 3;
    int ans = aggressiveCows(arr, k);
    cout << ans << endl;
    return 0;
}