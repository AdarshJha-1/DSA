#include <iostream>
using namespace std;

class MinHeap {
    int *arr;
    int size;
    int total_size;

public:
    MinHeap(int n) {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int val) {
        if(size == total_size) {
            cout << "size overflow" << endl;
            return;
        }
        arr[size] = val;
        int idx = size++;

        while(idx > 0 && arr[idx] < arr[(idx - 1)/2]) {
            swap(arr[idx], arr[(idx - 1)/2]);
            idx = (idx - 1) /2;
        }
    }

    void deleteMH() {
        if(size == 0) {
            cout << "size underflow" << endl;
            return;
        }

        int idx = 0;
        arr[idx] = arr[--size];
        while(true) {
            int p = idx, l = idx * 2 + 1, r = idx * 2 + 2;
            if(l < size && arr[l] < arr[p]) p = l;
            if(r < size && arr[r] < arr[p]) p = r;

            if(p == idx) break;
            swap(arr[p], arr[idx]);
            idx = p;
        }
    }

    void printMinHeap() {
        if(size == 0) {
            cout << "empty min-heap" << endl;
            return;
        }
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void BuildMinHeap(int *arr, int n) {
    for(int i = n / 2 - 1; i >= 0; i--) {
        int temp = i;
        while(temp * 2 + 1 < n) {
            int l = temp, lf = temp * 2 + 1, rg = temp * 2 + 2;
            if(lf < n && arr[lf] < arr[l]) l = lf;
            if(rg < n && arr[rg] < arr[l]) l = rg;

            if(l== temp) break;
            swap(arr[l], arr[temp]);
            temp = l;
        }
    }    
}
int main() {
    MinHeap *mh = new MinHeap(7);
    mh->insert(19);
    mh->insert(21);
    mh->insert(9);
    mh->insert(6);
    mh->insert(7);
    mh->insert(3);
    mh->insert(1);

    mh->printMinHeap();
    // mh->deleteMH();
    // mh->printMinHeap();
    // mh->deleteMH();
    // mh->printMinHeap();
    // mh->deleteMH();
    int n = 7;
    int arr[] = {19,21,9,6,7,3,1};
    BuildMinHeap(arr, n);
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
