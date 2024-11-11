#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;
    int mid;
    while(start <= end) {
        mid = start + (end - start) / 2;
        if(arr[mid] == target) {
            return mid;
        }else if(arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return - 1;
}

int main() {
    int arr[] = {22,32,232,24343,32223};
    int target = 22;
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = binarySearch(arr,n, target);
    if (ans != -1) {
     cout << "Found at index: " << ans << " Value: " << arr[ans] << endl ;
    }else {
        cout << "Value not found" << endl;
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}