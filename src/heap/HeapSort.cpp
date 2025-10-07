#include <iostream>
using namespace std;


void CovertToMaxHeap(int *arr, int n) {
    for(int i = n/2 - 1; i >= 0; i--) {
        int temp = i;
        while(temp * 2 + 1 < n){
            int l = temp, lf = temp * 2 + 1, rg = temp * 2 + 2;
            if(lf < n && arr[lf] > arr[l]) l = lf;
            if(rg < n && arr[rg] > arr[l]) l = rg;
            if(temp == l) break;
            swap(arr[temp], arr[l]);
            temp = l;
        }
    }
}

void heapify(int *arr, int i, int n) {
   while(i * 2 + 1 < n) {
        int l = i, lf = i * 2 + 1, rg = i * 2 + 2;
        if(lf < n && arr[lf] > arr[l]) l = lf;
        if(rg < n && arr[rg] > arr[l]) l = rg;
        if(i == l) break;
        swap(arr[l], arr[i]);
        i = l;
    } 
}

void heapSort(int *arr, int n) {
    CovertToMaxHeap(arr, n);
    for(int i =  n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }
}

int main() {

    int n = 6; 
    int arr1[] = {4,9,19,11,24,12};
    heapSort(arr1, n);
    for(int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    return 0;
}
