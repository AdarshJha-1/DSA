#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class MaxHeap {

    int *arr;
    int size;
    int total_size;

public:
    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int value) {
        if(size == total_size) {
            cout << "size overflow" << endl;
            return;
        }

        arr[size] = value;
        int idx = size++;

        while(idx > 0 && arr[(idx - 1)/2] < arr[idx]) {
            swap(arr[(idx - 1)/2], arr[idx]);
            idx = (idx - 1)/ 2;
        }
    }

    void deleteMH() {
        if(size == 0) {
            cout << "empty max-heap" << endl;
            return;
        }
        int idx = 0;
        arr[idx] = arr[--size];
        while(true) {
            int l = idx * 2 + 1;
            int r = idx * 2 + 2;
            int largest = idx;
            if(l < size && arr[l] >arr[largest]) {
                largest = l;
            }
            if(r < size && arr[r] >arr[largest]) {
                largest = r;
            }

            if(largest == idx) break;
            swap(arr[largest], arr[idx]);
            idx = largest;
        }
    }


    void printMaxHeap() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    MaxHeap *mh = new MaxHeap(7);
    mh->insert(4);
    mh->insert(9);
    mh->insert(19);
    mh->insert(11);
    mh->insert(24);
    mh->insert(12);
    mh->insert(29);
    
    mh->printMaxHeap();

    mh->deleteMH();
    mh->printMaxHeap();

    mh->deleteMH();
    mh->printMaxHeap();
    return 0;
}
