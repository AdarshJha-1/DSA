#include <iostream>
#include <vector>

using namespace std;

int searchInRotatedArray(vector<int> arr, int target) {
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;

    while(s <= e) {
        int mid = s + (e - s) /2 ;
        if(arr[mid] == target) {
            return mid;
        }else if(arr[mid] >= arr[0]) {
            if(arr[s] <= target && target <= arr[mid]) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        } else {
            if(arr[mid] <= target && target <= arr[e]){
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }
    return ans;
}

int main() {
    // vector<int> arr = {4,6,8,10,1,2};
    vector<int> arr = {3,4,5,1,2};
    // vector<int> arr = {4,6,8,10,12,33};
    int ans = searchInRotatedArray(arr,3);


    cout << arr[ans] << endl << ans << endl;
    return 0;
}