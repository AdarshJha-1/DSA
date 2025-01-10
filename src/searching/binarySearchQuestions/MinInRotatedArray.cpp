#include <iostream>
#include <vector>

using namespace std;

int minInRotatedArray(vector<int> arr) {
    int s = 0;
    int e = arr.size() - 1;
    int ans = 0;

    if (arr[s] < arr[e]) {
        return ans;
    }
    while(s <= e) {
        int mid = s + (e - s) / 2;
        if(arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            ans = mid;
            e = mid -1;
        }
    }
    return ans;
}

int main() {
    // vector<int> arr = {4,6,8,10,1,2};
    vector<int> arr = {3,4,5,1,2};
    // vector<int> arr = {4,6,8,10,12,33};
    int ans = minInRotatedArray(arr);


    cout << arr[ans] << endl << ans << endl;
    return 0;
}