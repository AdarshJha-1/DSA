#include <iostream>

using namespace std;

int searchEle(int arr[], int target, int size) {
    for(int i = 0; i < size; i++) {
       if(arr[i] == target) {
        return i;
       } 
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 11, 7, 4};
    int target = 191;
    int size = sizeof(arr)/sizeof(arr[0]);
    int ans = searchEle(arr, target, size);
    cout << ans << endl;
    return 0;
}

