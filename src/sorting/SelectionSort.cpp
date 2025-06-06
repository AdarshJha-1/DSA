#include <iostream>

using namespace std;

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int index = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[index]) {
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
   
}

int main() {
    int arr[] = {10, 8, 2, 3, 1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}