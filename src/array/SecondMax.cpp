#include <iostream>
#include <climits>

using namespace std;

int secondMax(int arr[], int size) {
    int max = INT_MIN;
    int secondMax = INT_MIN;
    for(int i = 0; i < size; i++) {
        if(arr[i] > max ) {
            secondMax = max;
            max = arr[i];
        }
        if(arr[i] < max && arr[i] > secondMax) {
            secondMax = arr[i];
        }
    }
    return secondMax;
}

int main() {
    int arr[] = {23, 34, 34, 32,13, 30};
    int size = sizeof(arr)/sizeof(arr[0]);
    int ans = secondMax(arr, size);
    cout << ans << endl;
    return 0;
}